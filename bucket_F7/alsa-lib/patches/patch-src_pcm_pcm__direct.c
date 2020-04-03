--- src/pcm/pcm_direct.c.orig	2020-02-19 09:35:39 UTC
+++ src/pcm/pcm_direct.c
@@ -44,12 +44,17 @@
  *
  */
  
+#if !defined(__DragonFly__) && !defined(__OpenBSD__) \
+  && !(defined(__FreeBSD__) && __FreeBSD__ < 12)
 union semun {
 	int              val;    /* Value for SETVAL */
 	struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
 	unsigned short  *array;  /* Array for GETALL, SETALL */
+#ifdef __linux__
 	struct seminfo  *__buf;  /* Buffer for IPC_INFO (Linux specific) */
+#endif
 };
+#endif
  
 /*
  * FIXME:
