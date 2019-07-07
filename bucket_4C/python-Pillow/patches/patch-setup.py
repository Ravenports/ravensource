--- setup.py.orig	2019-07-02 19:13:39 UTC
+++ setup.py
@@ -465,9 +465,7 @@ class pil_build_ext(build_ext):
                 _add_directory(include_dirs, "/usr/X11/include")
 
         elif (
-            sys.platform.startswith("linux")
-            or sys.platform.startswith("gnu")
-            or sys.platform.startswith("freebsd")
+            sys.platform.startswith("nothing")
         ):
             for dirname in _find_library_dirs_ldconfig():
                 _add_directory(library_dirs, dirname)
