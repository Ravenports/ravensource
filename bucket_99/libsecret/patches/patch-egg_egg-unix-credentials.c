--- egg/egg-unix-credentials.c.orig	2024-02-23 09:53:23 UTC
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
