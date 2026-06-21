--- src/ui.c.orig	2026-06-13 17:25:29 UTC
+++ src/ui.c
@@ -285,7 +285,7 @@ open_file_finder(const char *commit)
 
 	if (!file_finder_read(&finder, commit)) {
 		file_finder_done(&finder);
-		return false;
+		return NULL;
 	}
 
 	getmaxyx(stdscr, finder.height, finder.width);
@@ -293,7 +293,7 @@ open_file_finder(const char *commit)
 	finder.win = newwin(finder.height, finder.width, 0, 0);
 	if (!finder.win) {
 		file_finder_done(&finder);
-		return false;
+		return NULL;
 	}
 
 	finder.keymap = get_keymap("search", STRING_SIZE("search"));
