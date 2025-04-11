--- lib/fuse.c.orig	2025-03-24 12:25:30 UTC
+++ lib/fuse.c
@@ -4917,7 +4917,11 @@ static void *fuse_prune_nodes(void *fuse
 	struct fuse *f = fuse;
 	int sleep_time;
 
+#if defined(__NetBSD__)
+	pthread_setname_np(pthread_self(), "%s", (void *)"fuse_prune_nodes");
+#else
 	pthread_setname_np(pthread_self(), "fuse_prune_nodes");
+#endif
 
 	while(1) {
 		sleep_time = fuse_clean_cache(f);
