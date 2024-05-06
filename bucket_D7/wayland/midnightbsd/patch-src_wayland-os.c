--- src/wayland-os.c.orig	2023-04-04 07:58:31 UTC
+++ src/wayland-os.c
@@ -42,6 +42,10 @@
 
 #include "wayland-os.h"
 
+#if !defined(SOL_LOCAL)
+#define SOL_LOCAL 0
+#endif
+
 static int
 set_cloexec_or_close(int fd)
 {
@@ -79,7 +83,7 @@ wl_os_socket_cloexec(int domain, int typ
 	return set_cloexec_or_close(fd);
 }
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__MidnightBSD__)
 int
 wl_os_socket_peercred(int sockfd, uid_t *uid, gid_t *gid, pid_t *pid)
 {
