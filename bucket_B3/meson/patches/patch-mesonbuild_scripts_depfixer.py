--- mesonbuild/scripts/depfixer.py.orig	2022-12-16 18:51:36 UTC
+++ mesonbuild/scripts/depfixer.py
@@ -485,7 +485,7 @@ def fix_rpath(fname: str, rpath_dirs_to_
             return
         if isinstance(new_rpath, str):
             new_rpath = new_rpath.encode('utf8')
-        fix_elf(fname, rpath_dirs_to_remove, new_rpath, verbose)
+        # never adjust rpath (meson authors are idiots)
         return
     except SystemExit as e:
         if isinstance(e.code, int) and e.code == 0:
