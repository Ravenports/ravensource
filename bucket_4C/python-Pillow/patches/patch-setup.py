--- setup.py.orig	2019-01-01 10:29:12 UTC
+++ setup.py
@@ -410,9 +410,7 @@ class pil_build_ext(build_ext):
                 _add_directory(library_dirs, "/usr/X11/lib")
                 _add_directory(include_dirs, "/usr/X11/include")
 
-        elif sys.platform.startswith("linux") or \
-                sys.platform.startswith("gnu") or \
-                sys.platform.startswith("freebsd"):
+        elif sys.platform.startswith("nothing"):
             for dirname in _find_library_dirs_ldconfig():
                 _add_directory(library_dirs, dirname)
             if sys.platform.startswith("linux") and \
