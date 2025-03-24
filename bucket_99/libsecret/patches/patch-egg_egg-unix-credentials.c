--- egg/egg-unix-credentials.c.orig	2025-03-18 22:16:57 UTC
+++ egg/egg-unix-credentials.c
@@ -48,6 +48,10 @@
 #include <ucred.h>
 #endif
 
+#if defined(__FreeBSD__) || defined(__NetBSD__)
+#undef LOCAL_CREDS
+#endif
+
 int
 egg_unix_credentials_read (int sock, pid_t *pid, uid_t *uid)
 {
