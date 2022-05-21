--- src/dpipe.c.orig	2022-05-21 05:11:05.035482000 +0200
+++ src/dpipe.c	2022-05-21 05:12:17.785698000 +0200
@@ -201,7 +201,11 @@
 
 	if (daemonize != 0)
 		daemon(0,0);
+#ifdef __linux__
 	else if (setpgrp() == -1) {
+#else
+        else if (setpgrp(0,getpid()) != 0) {
+#endif
 		fprintf(stderr,"Err: cannot create pgrp\n");
 		perror("setpgrp");
 		exit(1);
