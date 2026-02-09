--- misc/src/daemon.c.orig	2026-02-03 12:38:10 UTC
+++ misc/src/daemon.c
@@ -156,7 +156,7 @@ main(int argc, char *argv[])
 
 	for (i = 0; i < argc; i++) {
 		strncat(buffer, argv[i], strlen(argv[i]));
-		strncat(buffer, " ", 1);
+		strncat(buffer, " ", sizeof(buffer) - strlen(buffer) - 1);
 	}
 
 	buffer[strlen(buffer) - 1] = '\0';
