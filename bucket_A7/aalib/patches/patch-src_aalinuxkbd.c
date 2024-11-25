--- src/aalinuxkbd.c.orig	2001-04-26 14:37:31 UTC
+++ src/aalinuxkbd.c
@@ -200,7 +200,7 @@ static void vt_to_here(int num)
 static int rawmode_init(void)
 {
     if (!closed)
-	return;
+	return (0);
     mypid = getpid();
     if (tty_fd == -1) {
 	tty_fd = fileno(stdin);
