--- giscanner/ccompiler.py.orig	2018-04-09 05:40:56 UTC
+++ giscanner/ccompiler.py
@@ -130,7 +130,7 @@ class CCompiler(object):
 
                 # Ensure libraries are always linked as we are going to use ldd to work
                 # out their names later
-                if sys.platform != 'darwin':
+                if sys.platform != 'darwin' and sys.platform != 'sunos5':
                     args.append('-Wl,--no-as-needed')
 
         for library in libraries + extra_libraries:
