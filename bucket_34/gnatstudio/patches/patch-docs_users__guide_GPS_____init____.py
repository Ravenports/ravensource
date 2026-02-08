--- docs/users_guide/GPS/__init__.py.orig	2025-09-19 10:04:04 UTC
+++ docs/users_guide/GPS/__init__.py
@@ -2147,7 +2147,7 @@ class Console(GUI):
         pass  # implemented in Ada
 
     def write_with_links(self, text):
-        """
+        r"""
         Outputs some text on the console, highlighting the parts of it that
         match the regular expression registered by
         :func:`GPS.Console.create_link`.
@@ -4540,7 +4540,7 @@ class EditorHighlighter(object):
     """
 
     def __init__(self, pattern, action, index=0, secondary_action=None):
-        """
+        r"""
         Register a highlighter. The action is a Python function that takes a
         string as a parameter: the string being passed is the section of text
         which is highlighted.
@@ -7377,7 +7377,7 @@ class MDI(object):
 
     @staticmethod
     def file_selector(file_filter="empty", base_dir="", except_filter=""):
-        """
+        r"""
         Displays a modal file selector. The user selected file is returned,
         or a file with an empty name if :guilabel:`Cancel` is pressed.
 
@@ -11086,7 +11086,7 @@ class XMLViewer(object):
     def __init__(
         self, name, columns=3, parser=None, on_click=None, on_select=None, sorted=False
     ):
-        """
+        r"""
         Creates a new XMLViewer, named ``name``.
 
         ``columns`` is the number of columns that the table representation
