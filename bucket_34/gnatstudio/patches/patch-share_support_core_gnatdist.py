--- share/support/core/gnatdist.py.orig	2025-09-19 10:04:04 UTC
+++ share/support/core/gnatdist.py
@@ -22,7 +22,7 @@ if gnatdist_tool == "":
 
 if gnatdist_tool != "":
     GPS.parse_xml(
-        """
+        r"""
   <Language>
     <Name>gnatdist</Name>
     <Parent>Ada</Parent>
