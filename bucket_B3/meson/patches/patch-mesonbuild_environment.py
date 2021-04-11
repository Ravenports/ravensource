--- mesonbuild/environment.py.orig	2021-04-10 09:22:14 UTC
+++ mesonbuild/environment.py
@@ -1191,7 +1191,7 @@ class Environment:
             else:
                 cls = GnuBFDDynamicLinker
             linker = cls(compiler, for_machine, comp_class.LINKER_PREFIX, override, version=v)
-        elif 'Solaris' in e or 'Solaris' in o:
+        elif 'enforce a 64-bit link-edit' in e:
             for line in (o+e).split('\n'):
                 if 'ld: Software Generation Utilities' in line:
                     v = line.split(':')[2].lstrip()
