--- share/support/core/gs_utils/highlighter.py.orig	2025-09-19 10:04:04 UTC
+++ share/support/core/gs_utils/highlighter.py
@@ -673,7 +673,7 @@ class Location_Highlighter(Background_Hi
 
 class Regexp_Highlighter(On_The_Fly_Highlighter):
 
-    """
+    r"""
     The Regexp_Highlighter is a concrete implementation to highlight
     editors based on regular expressions. One example is for instance
     to highlight tabs or trailing spaces on lines, when this is considered
