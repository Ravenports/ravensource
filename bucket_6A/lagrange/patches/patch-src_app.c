--- src/app.c.orig	2023-01-21 11:08:14 UTC
+++ src/app.c
@@ -729,7 +729,7 @@ static iBool loadState_App_(iApp *d) {
 //                printf("[State] '%.4s' split:%d state:%x\n", magic, splitMode, winState);
 #if defined (iPlatformTerminal)
                 /* Terminal only supports one window. */
-                win = d->window;
+                win = as_MainWindow(d->window);
 #else
                 if (numWins == 1) {
                     win = as_MainWindow(d->window);
