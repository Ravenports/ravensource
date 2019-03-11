--- giscanner/ccompiler.py.orig	2019-03-02 17:10:05 UTC
+++ giscanner/ccompiler.py
@@ -195,7 +195,7 @@ class CCompiler(object):
 
                 # Ensure libraries are always linked as we are going to use ldd to work
                 # out their names later
-                if sys.platform != 'darwin':
+                if sys.platform != 'darwin' and sys.platform != 'sunos5':
                     args.append('-Wl,--no-as-needed')
 
         for library_path in libpaths:
