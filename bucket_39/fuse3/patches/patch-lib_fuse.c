--- lib/fuse.c.orig	2025-04-23 23:16:19 UTC
+++ lib/fuse.c
@@ -4918,7 +4918,11 @@ static void *fuse_prune_nodes(void *fuse
 	int sleep_time;
 
 #ifdef HAVE_PTHREAD_SETNAME_NP
+# if defined(__NetBSD__)
+	pthread_setname_np(pthread_self(), "%s", (void *)"fuse_prune_nodes");
+# else
 	pthread_setname_np(pthread_self(), "fuse_prune_nodes");
+# endif
 #endif
 
 	while(1) {
