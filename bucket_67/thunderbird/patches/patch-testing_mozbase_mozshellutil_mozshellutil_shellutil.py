--- testing/mozbase/mozshellutil/mozshellutil/shellutil.py.orig	2026-03-20 21:42:40 UTC
+++ testing/mozbase/mozshellutil/mozshellutil/shellutil.py
@@ -181,6 +181,8 @@ def _quote(s):
     As a special case, if given an int, returns a string containing the int,
     not enclosed in quotes.
     """
+    if s is None:
+        s = ""
     if type(s) is int:
         return f"{s}"
 
