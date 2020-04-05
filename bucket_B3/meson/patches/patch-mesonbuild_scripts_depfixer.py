--- mesonbuild/scripts/depfixer.py.orig	2020-03-23 17:22:02 UTC
+++ mesonbuild/scripts/depfixer.py
@@ -441,15 +441,13 @@ def fix_rpath(fname, new_rpath, final_pa
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
-    # We don't look for this on import because it will do a useless PATH lookup
-    # on non-mac platforms. That can be expensive on some Windows machines
     # (upto 30ms), which is significant with --only-changed. For details, see:
     # https://github.com/mesonbuild/meson/pull/6612#discussion_r378581401
     if INSTALL_NAME_TOOL is False:
