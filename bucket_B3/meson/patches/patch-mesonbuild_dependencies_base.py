--- mesonbuild/dependencies/base.py.orig	2019-02-03 17:41:01 UTC
+++ mesonbuild/dependencies/base.py
@@ -1936,7 +1936,7 @@ class ExtraFrameworkDependency(ExternalD
     def detect(self, name, path):
         lname = name.lower()
         if path is None:
-            paths = ['/System/Library/Frameworks', '/Library/Frameworks']
+            paths = ['/System/Library/Frameworks']
         else:
             paths = [path]
         for p in paths:
