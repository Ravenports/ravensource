--- src/wayland-os.c.orig	2025-07-06 12:11:26 UTC
+++ src/wayland-os.c
@@ -42,6 +42,10 @@
 
 #include "wayland-os.h"
 
+#if !defined(SOL_LOCAL)
+#define SOL_LOCAL 0
+#endif
+
 /* used by tests */
 int (*wl_fcntl)(int fildes, int cmd, ...) = fcntl;
 int (*wl_socket)(int domain, int type, int protocol) = socket;
@@ -85,7 +89,7 @@ wl_os_socket_cloexec(int domain, int typ
 	return set_cloexec_or_close(fd);
 }
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 int
 wl_os_socket_peercred(int sockfd, uid_t *uid, gid_t *gid, pid_t *pid)
 {
@@ -106,6 +110,21 @@ wl_os_socket_peercred(int sockfd, uid_t
 #endif
 	return 0;
 }
+#elif defined(__NetBSD__)
+int
+wl_os_socket_peercred(int sockfd, uid_t *uid, gid_t *gid, pid_t *pid)
+{
+	socklen_t len;
+	struct sockcred ucred;
+
+	len = sizeof(ucred);
+	if (getsockopt(sockfd, SOL_LOCAL, LOCAL_CREDS, &ucred, &len) < 0)
+		return -1;
+	*uid = ucred.sc_uid;
+	*gid = ucred.sc_gid;
+	*pid = 0;
+	return 0;
+}
 #elif defined(SO_PEERCRED)
 int
 wl_os_socket_peercred(int sockfd, uid_t *uid, gid_t *gid, pid_t *pid)
