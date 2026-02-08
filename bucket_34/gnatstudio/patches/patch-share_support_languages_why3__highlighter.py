--- share/support/languages/why3_highlighter.py.orig	2025-09-19 10:04:04 UTC
+++ share/support/languages/why3_highlighter.py
@@ -48,7 +48,7 @@ keywords = "|".join(
     ]
 )
 
-comment_region = region(r"\(\*", "\*\)", tag=tag_comment)
+comment_region = region(r"\(\*", r"\*\)", tag=tag_comment)
 
 ada_keywords = "|".join(["True", "False"])
 
