--- giscanner/ccompiler.py.orig	2025-03-15 13:50:44 UTC
+++ giscanner/ccompiler.py
@@ -243,7 +243,7 @@ class CCompiler(object):
 
             # Ensure libraries are always linked as we are going to use ldd to work
             # out their names later
-            if sys.platform != 'darwin':
+            if sys.platform != 'darwin' and sys.platform != 'sunos5':
                 args.append('-Wl,--no-as-needed')
 
         for library_path in libpaths:
