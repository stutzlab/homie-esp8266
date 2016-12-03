   def _unlock_state_file(self):
        if self._lockfile:
            self._lockfile.release()


class LocalCache(object):

    def __init__(self, cache_dir=None):
        self.cache_dir = cache_dir or join(util.get_home_dir(), ".cache")
        if not self.cache_dir:
            os.makedirs(self.cache_dir)
        self.db_path = join(self.cache_dir, "db.data")

    def __enter__(self):
        if not isfile(self.db_path):
            return self
        newlines = []
        found = False
        with open(self.db_path) as fp:
            for line in fp.readlines():
                if "=" not in line:
                    continue
                line = line.strip()
                expire, path = line.split("=")
                if time() < int(expire):
                    newlines.append(line)
                    continue
                found = True
                if isfile(path):
                    remove(path)
                    if not len(listdir(dirname(path))):
                        util.rmtree_(dirname(path))
        if found:
            with open(self.db_path, "w") as fp:
                fp.write("\n".join(newlines) + "\n")
        return self

    def __exit__(self, type_, value, traceback):
        pass

    def get_cache_path(self, key):
        assert len(key) > 3
        return join(self.cache_dir, key[-2:], key)

    @staticmethod
    def key_from_args(*args):
        h = hashlib.md5()
        for data in args:
            h.update(str(data))
        return h.hexdigest()

    def get(self, key):
        cache_path = self.get_cache_path(key)
        if not isfile(cache_path):
            return None
        with open(cache_path) as fp:
            data = fp.read()
            if data[0] in ("{", "["):
                return json.loads(data)
            return data

    def set(self, key, data, valid):
        if not data:
            return
       