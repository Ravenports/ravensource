--- mesonbuild/environment.py.orig	2019-11-28 17:37:44 UTC
+++ mesonbuild/environment.py
@@ -822,7 +822,7 @@ class Environment:
             else:
                 i = 'GNU ld.bfd'
             linker = GnuDynamicLinker(compiler, for_machine, i, prefix, version=v)
-        elif 'Solaris' in e or 'Solaris' in o:
+        elif 'enforce a 64-bit link-edit' in e:
             linker = SolarisDynamicLinker(
                 compiler, for_machine, 'solaris', prefix,
                 version=search_version(e))
