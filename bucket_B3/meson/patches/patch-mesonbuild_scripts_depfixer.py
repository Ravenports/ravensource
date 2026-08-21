--- mesonbuild/scripts/depfixer.py.orig	2026-08-21 01:26:13 UTC
+++ mesonbuild/scripts/depfixer.py
@@ -824,8 +824,7 @@ def fix_rpath(fname: str, rpath_dirs_to_
             return
         if system == 'aix':
             fix_aix(fname, rpath_dirs_to_remove, new_rpath, verbose)
-        else:
-            fix_elf(fname, rpath_dirs_to_remove, new_rpath, verbose)
+        # never adjust rpath on Ravenports platforms (meson authors are idiots)
         return
     except SystemExit as e:
         if isinstance(e.code, int) and e.code == 0:
