--- tools/gyp/pylib/gyp/common.py.orig	2019-11-05 16:56:32 UTC
+++ tools/gyp/pylib/gyp/common.py
@@ -426,6 +426,8 @@ def GetFlavor(params):
     return 'freebsd'
   if sys.platform.startswith('dragonfly'):
     return 'freebsd'
+  if sys.platform.startswith('dragon'):
+    return 'freebsd'
   if sys.platform.startswith('openbsd'):
     return 'openbsd'
   if sys.platform.startswith('netbsd'):
