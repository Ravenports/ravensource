--- lib/fuse_loop_mt.c.orig	2025-03-24 12:25:30 UTC
+++ lib/fuse_loop_mt.c
@@ -132,7 +132,11 @@ static void *fuse_do_work(void *data)
 	struct fuse_worker *w = (struct fuse_worker *) data;
 	struct fuse_mt *mt = w->mt;
 
+#if defined(__NetBSD__)
+	pthread_setname_np(pthread_self(), "%s", (void *)"fuse_worker");
+#else
 	pthread_setname_np(pthread_self(), "fuse_worker");
+#endif
 
 	while (!fuse_session_exited(mt->se)) {
 		int isforget = 0;
