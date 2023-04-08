--- tests/os-wrappers-test.c.orig	2023-04-04 07:58:31 UTC
+++ tests/os-wrappers-test.c
@@ -39,7 +39,6 @@
 #include <stdarg.h>
 #include <fcntl.h>
 #include <stdio.h>
-#include <sys/epoll.h>
 
 #include "wayland-private.h"
 #include "test-runner.h"
@@ -152,15 +151,7 @@ recvmsg(int sockfd, struct msghdr *msg,
 __attribute__ ((visibility("default"))) int
 epoll_create1(int flags)
 {
-	wrapped_calls_epoll_create1++;
-
-	if (fall_back) {
-		wrapped_calls_epoll_create1++; /* epoll_create() not wrapped */
-		errno = EINVAL;
-		return -1;
-	}
-
-	return real_epoll_create1(flags);
+	return 0;
 }
 
 static void
@@ -375,6 +366,7 @@ TEST(os_wrappers_recvmsg_cloexec_fallbac
 	do_os_wrappers_recvmsg_cloexec(1);
 }
 
+#if !defined(__DragonFly__)
 static void
 do_os_wrappers_epoll_create_cloexec(int n)
 {
@@ -406,5 +398,6 @@ TEST(os_wrappers_epoll_create_cloexec_fa
 	init_fallbacks(1);
 	do_os_wrappers_epoll_create_cloexec(2);
 }
+#endif
 
 /* FIXME: add tests for wl_os_accept_cloexec() */
