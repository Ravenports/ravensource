--- ../../python/mach/mach/mixin/process.py.orig	2018-04-01 13:37:29.893787000 +0200
+++ ../../python/mach/mach/mixin/process.py	2018-04-01 13:38:10.188973000 +0200
@@ -26,7 +26,7 @@
 elif 'COMSPEC' in os.environ:
     _current_shell = os.environ['COMSPEC']
 else:
-    raise Exception('Could not detect environment shell!')
+    _current_shell = "/bin/sh"
 
 _in_msys = False
 
