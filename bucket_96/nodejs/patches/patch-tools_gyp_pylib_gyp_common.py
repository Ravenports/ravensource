--- tools/gyp/pylib/gyp/common.py.orig	2020-01-21 16:26:44 UTC
+++ tools/gyp/pylib/gyp/common.py
@@ -430,6 +430,8 @@ def GetFlavor(params):
     return 'freebsd'
   if sys.platform.startswith('dragonfly'):
     return 'freebsd'
+  if sys.platform.startswith('dragon'):
+    return 'freebsd'
   if sys.platform.startswith('openbsd'):
     return 'openbsd'
   if sys.platform.startswith('netbsd'):
