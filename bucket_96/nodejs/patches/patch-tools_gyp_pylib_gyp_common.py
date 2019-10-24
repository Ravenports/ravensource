--- tools/gyp/pylib/gyp/common.py.orig	2019-10-23 09:52:41 UTC
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
