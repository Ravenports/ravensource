--- tools/gyp/pylib/gyp/common.py.orig	2019-10-01 13:32:44 UTC
+++ tools/gyp/pylib/gyp/common.py
@@ -423,6 +423,8 @@ def GetFlavor(params):
     return 'freebsd'
   if sys.platform.startswith('dragonfly'):
     return 'freebsd'
+  if sys.platform.startswith('dragon'):
+    return 'freebsd'
   if sys.platform.startswith('openbsd'):
     return 'openbsd'
   if sys.platform.startswith('netbsd'):
