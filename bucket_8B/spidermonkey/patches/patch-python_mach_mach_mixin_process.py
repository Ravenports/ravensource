--- ../../python/mach/mach/mixin/process.py.orig	2019-05-05 01:09:36 UTC
+++ ../../python/mach/mach/mixin/process.py
@@ -26,7 +26,7 @@ elif 'MOZILLABUILD' in os.environ:
 elif 'COMSPEC' in os.environ:
     _current_shell = os.environ['COMSPEC']
 else:
-    raise Exception('Could not detect environment shell!')
+    _current_shell = "/bin/sh"
 
 _in_msys = False
 
