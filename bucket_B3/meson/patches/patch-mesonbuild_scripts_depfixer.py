--- mesonbuild/scripts/depfixer.py.orig	2025-04-06 19:57:59 UTC
+++ mesonbuild/scripts/depfixer.py
@@ -468,7 +468,7 @@ def fix_rpath(fname: str, rpath_dirs_to_
             return
         if isinstance(new_rpath, str):
             new_rpath = new_rpath.encode('utf8')
-        fix_elf(fname, rpath_dirs_to_remove, new_rpath, verbose)
+        # never adjust rpath (meson authors are idiots)
         return
     except SystemExit as e:
         if isinstance(e.code, int) and e.code == 0:
