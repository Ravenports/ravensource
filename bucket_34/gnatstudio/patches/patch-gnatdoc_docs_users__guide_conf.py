--- gnatdoc/docs/users_guide/conf.py.orig	2023-05-10 09:41:12 UTC
+++ gnatdoc/docs/users_guide/conf.py
@@ -53,7 +53,8 @@ def get_version():
     version_file = "../../../VERSION.txt"
     if os.path.isfile(version_file):
         return open(version_file).readline()
-    raise Exception("Cannot find version number")
+    else:
+        return "0.0"
 
 # The version info for the project you're documenting, acts as replacement for
 # |version| and |release|, also used in various other places throughout the
