--- tools/gyp/pylib/gyp/common.py.orig	2019-08-06 20:46:26 UTC
+++ tools/gyp/pylib/gyp/common.py
@@ -421,6 +421,8 @@ def GetFlavor(params):
     return 'solaris'
   if sys.platform.startswith('freebsd'):
     return 'freebsd'
+  if sys.platform.startswith('dragon'):
+    return 'freebsd'
   if sys.platform.startswith('openbsd'):
     return 'openbsd'
   if sys.platform.startswith('netbsd'):
