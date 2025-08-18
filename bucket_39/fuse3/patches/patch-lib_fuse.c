--- lib/fuse.c.orig	2025-07-19 12:34:56 UTC
+++ lib/fuse.c
@@ -4893,7 +4893,11 @@ static void *fuse_prune_nodes(void *fuse
 	int sleep_time;
 
 #ifdef HAVE_PTHREAD_SETNAME_NP
+# if defined(__NetBSD__)
+	pthread_setname_np(pthread_self(), "%s", (void *)"fuse_prune_nodes");
+# else
 	pthread_setname_np(pthread_self(), "fuse_prune_nodes");
+# endif
 #endif
 
 	while(1) {
