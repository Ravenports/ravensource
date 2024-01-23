--- src/wayland-os.h.orig	2023-04-04 07:58:31 UTC
+++ src/wayland-os.h
@@ -42,7 +42,7 @@ ssize_t
 wl_os_recvmsg_cloexec(int sockfd, struct msghdr *msg, int flags);
 
 int
-wl_os_epoll_create_cloexec(void);
+wl_os_kqueue_create_cloexec(void);
 
 int
 wl_os_accept_cloexec(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
