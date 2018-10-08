--- mesonbuild/dependencies/base.py.orig	2018-08-25 08:05:50 UTC
+++ mesonbuild/dependencies/base.py
@@ -1080,7 +1080,7 @@ class ExtraFrameworkDependency(ExternalD
     def detect(self, name, path):
         lname = name.lower()
         if path is None:
-            paths = ['/System/Library/Frameworks', '/Library/Frameworks']
+            paths = ['/System/Library/Frameworks']
         else:
             paths = [path]
         for p in paths:
