$NetBSD: patch-osdep_threads-posix.h,v 1.1 2024/01/01 15:50:14 leot Exp $

Add support for NetBSD.

--- osdep/threads-posix.h.orig	2024-09-23 17:36:41 UTC
+++ osdep/threads-posix.h
@@ -236,6 +236,8 @@ static inline void mp_thread_set_name(co
     pthread_set_name_np(pthread_self(), name);
 #elif HAVE_MAC_THREAD_NAME
     pthread_setname_np(name);
+#elif HAVE_NETBSD_THREAD_NAME
+    pthread_setname_np(pthread_self(), "%s", name);
 #endif
 }
 
