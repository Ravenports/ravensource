--- mesonbuild/dependencies/base.py.orig	2019-01-23 16:46:09 UTC
+++ mesonbuild/dependencies/base.py
@@ -1941,7 +1941,7 @@ class ExtraFrameworkDependency(ExternalD
 
         lname = name.lower()
         if path is None:
-            paths = ['/System/Library/Frameworks', '/Library/Frameworks']
+            paths = ['/System/Library/Frameworks']
         else:
             paths = [path]
         for p in paths:
