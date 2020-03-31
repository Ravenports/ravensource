--- src/dpipe.c.orig	2011-11-23 16:41:18 UTC
+++ src/dpipe.c
@@ -201,7 +201,11 @@ int main(int argc, char *argv[])
 
 	if (daemonize != 0)
 		daemon(0,0);
+#ifdef __linux__
 	else if (setpgrp() != 0) {
+#else
+	else if (setpgrp(0,getpid()) != 0) {
+#endif
 		fprintf(stderr,"Err: cannot create pgrp\n");
 		exit(1);
 	}
