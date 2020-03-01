--- setup.py.orig	2020-02-16 15:40:19 UTC
+++ setup.py
@@ -531,8 +531,6 @@ class build(du_build):
 
 def main():
 
-    if sys.version_info[0] < 3:
-        raise Exception("Python 2 no longer supported")
 
     cairo_ext = Extension(
         name='cairo._cairo',
