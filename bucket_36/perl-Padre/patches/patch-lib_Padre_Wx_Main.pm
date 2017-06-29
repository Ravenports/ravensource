--- lib/Padre/Wx/Main.pm.orig	2013-11-09 03:43:41 UTC
+++ lib/Padre/Wx/Main.pm
@@ -5561,7 +5561,7 @@ sub on_prev_pane {
 
     $main->on_join_lines;
 
-Join current line with next one (à la B<vi> with C<Ctrl+J>). No return value.
+Join current line with next one. No return value.
 
 =cut
 
