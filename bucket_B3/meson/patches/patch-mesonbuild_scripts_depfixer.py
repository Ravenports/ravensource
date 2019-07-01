--- mesonbuild/scripts/depfixer.py.orig	2019-05-05 19:11:16 UTC
+++ mesonbuild/scripts/depfixer.py
@@ -439,12 +439,10 @@ def fix_rpath(fname, new_rpath, final_pa
         if fname.endswith('.jar'):
             fix_jar(fname)
             return
-        fix_elf(fname, new_rpath, verbose)
+        # never adjust rpath (meson authors are idiots)
         return
     except SystemExit as e:
         if isinstance(e.code, int) and e.code == 0:
             pass
         else:
             raise
-    if shutil.which('install_name_tool'):
-        fix_darwin(fname, new_rpath, final_path, install_name_mappings)
