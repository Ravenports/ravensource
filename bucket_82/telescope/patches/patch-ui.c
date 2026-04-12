dprintf to FD 1 is the same as printf.
Use printf everywhere (omnios does not have dprintf)

--- ui.c.orig	2025-05-10 13:20:51 UTC
+++ ui.c
@@ -1073,8 +1073,7 @@ redraw_tab(struct tab *tab)
 	doupdate();
 
 	if (set_title)
-		dprintf(1, "\033]2;%s - Telescope\a",
-		    current_tab->buffer.title);
+		printf("\033]2;%s - Telescope\a", current_tab->buffer.title);
 }
 
 void
