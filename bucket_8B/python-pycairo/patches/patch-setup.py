--- setup.py.orig	2020-01-23 21:00:13 UTC
+++ setup.py
@@ -531,8 +531,6 @@ class build(du_build):
 
 def main():
 
-    if sys.version_info[0] < 3:
-        raise Exception("Python 2 no longer supported")
 
     cairo_ext = Extension(
         name='cairo._cairo',
