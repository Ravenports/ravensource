--- src/pj_mutex.c.orig	2018-06-03 00:17:46.473280000 +0200
+++ src/pj_mutex.c	2018-06-03 00:18:42.093587000 +0200
@@ -119,7 +119,7 @@
     pthread_mutexattr_t mutex_attr;
 
     pthread_mutexattr_init(&mutex_attr);
-#ifdef HAVE_PTHREAD_MUTEX_RECURSIVE
+#if defined(HAVE_PTHREAD_MUTEX_RECURSIVE) || defined(__FreeBSD__) || defined(__DragonFly__)
     pthread_mutexattr_settype(&mutex_attr, PTHREAD_MUTEX_RECURSIVE);
 #else
     pthread_mutexattr_settype(&mutex_attr, PTHREAD_MUTEX_RECURSIVE_NP);
