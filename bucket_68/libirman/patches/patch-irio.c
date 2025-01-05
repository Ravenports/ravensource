--- irio.c.orig	2025-01-05 20:12:02.374191000 +0100
+++ irio.c	2025-01-05 20:12:35.681160000 +0100
@@ -97,14 +97,6 @@
     return -1;
   }
 
-  /* lock the file for ourselves */
-  if (flock(portfd, LOCK_EX | LOCK_NB) < 0) {
-    /* unable to get lock */
-    close(portfd);
-    portfd = 0;
-    return -1;
-  }
-
   /* get port attributes, store in oldterm */
   if (tcgetattr(portfd, &oldterm) < 0) {
     close(portfd);
