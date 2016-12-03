les())
        for lb in lib_builders:
            for deplb in lb.depbuilders[:]:
                if deplb not in found_lbs:
                    lb.depbuilders.remove(deplb)

    def print_deps_tree(root, level=0):
        margin = "|   " * (level)
        for lb in root.depbuilders:
            title = "<%s>" % lb.name
            if lb.version:
                title += " v%s" % lb.version
            if int(ARGUMENTS.get("PIOVERBOSE", 0)):
                title += " (%s)" % lb.path
            print "%s|-- %s" % (margin, title)
            if lb.depbuilders:
                print_deps_tree(lb, level + 1)

    lib_builders = env.GetLibBuilders()

    print "Collected %d com