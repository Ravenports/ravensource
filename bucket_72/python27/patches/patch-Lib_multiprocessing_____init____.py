--- Lib/multiprocessing/__init__.py.orig	2020-04-19 21:13:39 UTC
+++ Lib/multiprocessing/__init__.py
@@ -59,6 +59,7 @@ __author__ = 'R. Oudkerk (r.m.oudkerk@gm
 #
 
 import os
+import os.path
 import sys
 
 from multiprocessing.process import Process, current_process, active_children
@@ -115,15 +116,21 @@ def cpu_count():
             num = int(os.environ['NUMBER_OF_PROCESSORS'])
         except (ValueError, KeyError):
             num = 0
-    elif 'bsd' in sys.platform or sys.platform == 'darwin':
+    elif 'bsd' in sys.platform or sys.platform == 'darwin' or sys.platform.startswith('dragonfly'):
         comm = '/sbin/sysctl -n hw.ncpu'
         if sys.platform == 'darwin':
             comm = '/usr' + comm
-        try:
-            with os.popen(comm) as p:
-                num = int(p.read())
-        except ValueError:
-            num = 0
+        if os.path.isfile(comm):
+            try:
+                with os.popen(comm) as p:
+                    num = int(p.read())
+            except ValueError:
+                num = 0
+        else:
+            try:
+                num = os.sysconf('SC_NPROCESSORS_ONLN')
+            except (ValueError, OSError, AttributeError):
+                num = 0
     else:
         try:
             num = os.sysconf('SC_NPROCESSORS_ONLN')
