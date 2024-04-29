--- giscanner/ccompiler.py.orig	2024-04-01 13:21:25 UTC
+++ giscanner/ccompiler.py
@@ -232,7 +232,7 @@ class CCompiler(object):
 
                 # Ensure libraries are always linked as we are going to use ldd to work
                 # out their names later
-                if sys.platform != 'darwin':
+                if sys.platform != 'darwin' and sys.platform != 'sunos5':
                     args.append('-Wl,--no-as-needed')
 
         for library_path in libpaths:
