--- src/modules/module-protocol-pulse/utils.c.orig	2025-05-22 08:59:37 UTC
+++ src/modules/module-protocol-pulse/utils.c
@@ -86,6 +86,7 @@ int check_flatpak(struct client *client,
 	root_fd = openat(AT_FDCWD, root_path, O_RDONLY | O_NONBLOCK | O_DIRECTORY | O_CLOEXEC | O_NOCTTY);
 	if (root_fd == -1) {
 		res = -errno;
+#if !defined(__NetBSD__)
 		if (res == -EACCES) {
 			struct statfs buf;
 			/* Access to the root dir isn't allowed. This can happen if the root is on a fuse
@@ -96,6 +97,7 @@ int check_flatpak(struct client *client,
 			    buf.f_type == 0x65735546) /* FUSE_SUPER_MAGIC */
 				return 0;
 		}
+#endif
 		/* Not able to open the root dir shouldn't happen. Probably the app died and
 		 * we're failing due to /proc/$pid not existing. In that case fail instead
 		 * of treating this as privileged. */
@@ -124,8 +126,8 @@ int check_flatpak(struct client *client,
 
 pid_t get_client_pid(struct client *client, int client_fd)
 {
-	socklen_t len;
 #if defined(__linux__)
+	socklen_t len;
 	struct ucred ucred;
 	len = sizeof(ucred);
 	if (getsockopt(client_fd, SOL_SOCKET, SO_PEERCRED, &ucred, &len) < 0) {
@@ -133,6 +135,7 @@ pid_t get_client_pid(struct client *clie
 	} else
 		return ucred.pid;
 #elif defined(__FreeBSD__) || defined(__MidnightBSD__)
+	socklen_t len;
 	struct xucred xucred;
 	len = sizeof(xucred);
 	if (getsockopt(client_fd, 0, LOCAL_PEERCRED, &xucred, &len) < 0) {
