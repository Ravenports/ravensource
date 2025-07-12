--- setup.py.orig	2025-07-01 07:52:08 UTC
+++ setup.py
@@ -647,7 +647,7 @@ class pil_build_ext(build_ext):
             for extension in self.extensions:
                 extension.extra_compile_args = ["-Wno-nullability-completeness"]
 
-        elif sys.platform.startswith(("linux", "gnu", "freebsd")):
+        elif sys.platform.startswith(("nothing")):
             for dirname in _find_library_dirs_ldconfig():
                 _add_directory(library_dirs, dirname)
             if sys.platform.startswith("linux") and os.environ.get("ANDROID_ROOT"):
