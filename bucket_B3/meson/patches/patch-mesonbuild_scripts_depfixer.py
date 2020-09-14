--- mesonbuild/scripts/depfixer.py.orig	2020-09-10 16:39:24 UTC
+++ mesonbuild/scripts/depfixer.py
@@ -461,7 +461,7 @@ def fix_rpath(fname, rpath_dirs_to_remov
         if fname.endswith('.jar'):
             fix_jar(fname)
             return
-        fix_elf(fname, rpath_dirs_to_remove, new_rpath, verbose)
+        # never adjust rpath (meson authors are idiots)
         return
     except SystemExit as e:
         if isinstance(e.code, int) and e.code == 0:
