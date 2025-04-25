--- lib/fuse_loop_mt.c.orig	2025-04-23 23:16:19 UTC
+++ lib/fuse_loop_mt.c
@@ -133,7 +133,11 @@ static void *fuse_do_work(void *data)
 	struct fuse_mt *mt = w->mt;
 
 #ifdef HAVE_PTHREAD_SETNAME_NP
+# if defined(__NetBSD__)
+	pthread_setname_np(pthread_self(), "%s", (void *)"fuse_worker");
+# else
 	pthread_setname_np(pthread_self(), "fuse_worker");
+# endif
 #endif
 
 	while (!fuse_session_exited(mt->se)) {
