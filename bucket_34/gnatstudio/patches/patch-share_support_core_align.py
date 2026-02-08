--- share/support/core/align.py.orig	2025-09-19 10:04:04 UTC
+++ share/support/core/align.py
@@ -495,7 +495,7 @@ def align_formal_params():
     """
     # The regexp needs the three nested groups, since we want \\1 to always
     # returns at least the empty string
-    buffer_align_on(sep=":\s*(((in\s+out|out|in|access) )?)", replace_with=" : \\1")
+    buffer_align_on(sep=r":\s*(((in\s+out|out|in|access) )?)", replace_with=r" : \\1")
 
 
 @interactive(
@@ -523,7 +523,7 @@ def align_end_of_line_comments():
     buffer = GPS.EditorBuffer.get()
     lang = buffer.file().language().lower()
     if lang in ("ada", "project file"):
-        buffer_align_on(sep="\s*[^\s]+\s*( --\s*)", replace_with=" --  ", sep_group=1)
+        buffer_align_on(sep=r"\s*[^\s]+\s*( --\s*)", replace_with=" --  ", sep_group=1)
     else:
-        buffer_align_on(sep=" //\s*", replace_with=" // ")
-        buffer_align_on(sep=" #\s*", replace_with=" # ")
+        buffer_align_on(sep=r" //\s*", replace_with=r" // ")
+        buffer_align_on(sep=r" #\s*", replace_with=r" # ")
