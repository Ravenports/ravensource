--- share/support/languages/xml_support.py.orig	2025-09-19 10:04:04 UTC
+++ share/support/languages/xml_support.py
@@ -166,7 +166,7 @@ def goto_matching_tag():
 
 
 parse_xml(
-    """
+    r"""
   <Language>
     <Name>XML</Name>
     <Body_Suffix>.xml</Body_Suffix>
