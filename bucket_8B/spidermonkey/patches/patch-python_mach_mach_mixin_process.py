--- ../../python/mach/mach/mixin/process.py.orig	2020-08-17 18:34:22 UTC
+++ ../../python/mach/mach/mixin/process.py
@@ -28,7 +28,7 @@ elif 'MOZILLABUILD' in os.environ:
 elif 'COMSPEC' in os.environ:
     _current_shell = os.environ['COMSPEC']
 else:
-    raise Exception('Could not detect environment shell!')
+    _current_shell = "/bin/sh"
 
 _in_msys = False
 
