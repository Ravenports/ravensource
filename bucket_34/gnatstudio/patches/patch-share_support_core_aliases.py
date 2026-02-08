--- share/support/core/aliases.py.orig	2025-09-19 10:04:04 UTC
+++ share/support/core/aliases.py
@@ -12,13 +12,13 @@ from text_utils import goto_word_start
 import re
 from color_utils import Color
 
-subst_pattern = re.compile("%\(.*?\)|%_")
+subst_pattern = re.compile(r"%\(.*?\)|%_")
 # The regexp used to detect aliases parameters
 
-lsp_subst_pattern = re.compile("\${[^}]*}|\$[0-9]")
+lsp_subst_pattern = re.compile(r"\${[^}]*}|\$[0-9]")
 # The regexp used to detect LSP snippets parameters
 
-lsp_get_placeholder = re.compile("\${[0-9]+:([^}]*)}")
+lsp_get_placeholder = re.compile(r"\${[0-9]+:([^}]*)}")
 
 color_pref_name = "Src-Editor-Ephemeral-Smart"
 
