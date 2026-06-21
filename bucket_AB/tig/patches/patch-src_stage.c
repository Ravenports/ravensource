--- src/stage.c.orig	2026-06-13 17:25:29 UTC
+++ src/stage.c
@@ -347,7 +347,7 @@ stage_insert_chunk(struct view *view, st
 		const char *text = box_text(line);
 
 		if (!add_line_text_at(view, after_lineno++, text, line->type, 1))
-			return false;
+			return NULL;
 	}
 
 	return view->line + after_lineno;
