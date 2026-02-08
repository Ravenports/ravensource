--- share/support/core/gnathub.py.orig	2025-09-19 10:04:04 UTC
+++ share/support/core/gnathub.py
@@ -18,14 +18,14 @@ class GNAThub_Parser(tool_output.OutputP
         self.open_report = False
         if NEED_INIT:
             GPS.Console().create_link(
-                "\[PASSED\]",
+                r"\[PASSED\]",
                 lambda x: None,
                 foreground="green",
                 background="",
                 underline=False,
             )
             GPS.Console().create_link(
-                "\[FAILED\]",
+                r"\[FAILED\]",
                 lambda x: None,
                 foreground="red",
                 background="",
