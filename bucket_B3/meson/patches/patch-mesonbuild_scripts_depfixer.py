--- mesonbuild/scripts/depfixer.py.orig	2019-08-28 17:15:39 UTC
+++ mesonbuild/scripts/depfixer.py
@@ -438,12 +438,10 @@ def fix_rpath(fname, new_rpath, final_pa
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
