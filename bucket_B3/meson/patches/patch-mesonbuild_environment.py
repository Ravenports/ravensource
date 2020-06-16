--- mesonbuild/environment.py.orig	2020-06-14 19:40:08 UTC
+++ mesonbuild/environment.py
@@ -893,7 +893,7 @@ class Environment:
             else:
                 cls = GnuBFDDynamicLinker
             linker = cls(compiler, for_machine, comp_class.LINKER_PREFIX, override, version=v)
-        elif 'Solaris' in e or 'Solaris' in o:
+        elif 'enforce a 64-bit link-edit' in e:
             linker = SolarisDynamicLinker(
                 compiler, for_machine, comp_class.LINKER_PREFIX, override,
                 version=search_version(e))
