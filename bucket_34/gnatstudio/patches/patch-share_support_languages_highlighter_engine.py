--- share/support/languages/highlighter/engine.py.orig	2025-09-19 10:04:04 UTC
+++ share/support/languages/highlighter/engine.py
@@ -635,7 +635,7 @@ class Highlighter(object):
         gtk_ed.connect("insert-text", highlighting_insert_text_before)
 
     def generate_markup(self, text, allow_nested_tag=False):
-        """
+        r"""
         Generate the pango markup representation of text by Highlighter.
         :param allow_nested_tag: When True, insert markup for each tags.
         Otherwise skip nested tags.
