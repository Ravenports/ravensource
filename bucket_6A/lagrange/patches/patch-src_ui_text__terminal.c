--- src/ui/text_terminal.c.orig	2023-01-21 11:08:14 UTC
+++ src/ui/text_terminal.c
@@ -206,6 +206,6 @@ static float nextTabStop_Font_(const iFo
 
 #include "text_simple.c"
 
-iRect run_Font(iBaseFont *font, const iRunArgs *args) {
+void run_Font(iBaseFont *font, const iRunArgs *args) {
     return runSimple_Font_((iFont *) font, args);
 }
