$NetBSD: patch-ttyio.c,v 1.2 2023/04/25 21:53:01 nikita Exp $

SunOS needs sys/filio.h for FIONREAD.

--- ttyio.c.orig	2024-07-09 15:39:50 UTC
+++ ttyio.c
@@ -14,6 +14,9 @@
 #include <sys/queue.h>
 #include <sys/time.h>
 #include <sys/types.h>
+#ifdef __sun
+#include <sys/filio.h>
+#endif
 #include <errno.h>
 #include <fcntl.h>
 #include <poll.h>
