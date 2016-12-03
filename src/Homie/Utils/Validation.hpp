aScript")
        return LibBuilderBase.extra_script.fget(self)

    @property
    def lib_archive(self):
        if "libArchive" in self._manifest.get("build", {}):
            return self._manifest.get("build").get("libArchive")
        return LibBuilderBase.lib_archive.fget(self)

    @property
    def lib_ldf_mode(self):
        if "libLDFMode" in self._manifest.get("build", {}):
            return int(self._manifest.get("build").get("libLDFMode"))
        return LibBuilderBase.lib_ldf_mode.fget(self)

    def is_platforms_compatible(self, platforms):
        items = self._manifest.get("platforms")
        if not items:
            return LibBuilderBase.is_platforms_compatible(self, platforms)
        return self.items_in_list(platforms, items)

    d