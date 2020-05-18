--- mesonbuild/environment.py.orig	2020-05-15 07:23:18 UTC
+++ mesonbuild/environment.py
@@ -890,7 +890,7 @@ class Environment:
             else:
                 cls = GnuBFDDynamicLinker
             linker = cls(compiler, for_machine, comp_class.LINKER_PREFIX, override, version=v)
-        elif 'Solaris' in e or 'Solaris' in o:
+        elif 'enforce a 64-bit link-edit' in e:
             linker = SolarisDynamicLinker(
                 compiler, for_machine, comp_class.LINKER_PREFIX, override,
                 version=search_version(e))
