--- mesonbuild/environment.py.orig	2020-01-07 19:29:59 UTC
+++ mesonbuild/environment.py
@@ -857,7 +857,7 @@ class Environment:
             else:
                 i = 'GNU ld.bfd'
             linker = GnuDynamicLinker(compiler, for_machine, i, comp_class.LINKER_PREFIX, override, version=v)
-        elif 'Solaris' in e or 'Solaris' in o:
+        elif 'enforce a 64-bit link-edit' in e:
             linker = SolarisDynamicLinker(
                 compiler, for_machine, 'solaris', comp_class.LINKER_PREFIX, override,
                 version=search_version(e))
