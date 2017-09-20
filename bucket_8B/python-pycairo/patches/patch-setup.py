--- setup.py.orig	2017-09-17 20:00:35 UTC
+++ setup.py
@@ -130,7 +130,7 @@ class install_pkgconfig(Command):
         if self.compiler_type == "msvc":
             return
 
-        pkgconfig_dir = os.path.join(self.install_data, "share", "pkgconfig")
+        pkgconfig_dir = os.path.join(self.install_data, "lib", "pkgconfig")
         self.mkpath(pkgconfig_dir)
 
         if sys.version_info[0] == 3:
