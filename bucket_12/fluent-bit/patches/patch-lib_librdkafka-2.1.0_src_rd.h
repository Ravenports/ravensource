--- lib/librdkafka-2.1.0/src/rd.h.orig	2023-07-12 22:47:35 UTC
+++ lib/librdkafka-2.1.0/src/rd.h
@@ -39,6 +39,10 @@
 #define _DARWIN_C_SOURCE /* for strlcpy, pthread_setname_np, etc */
 #endif
 
+#if defined(__NetBSD__)
+#define _XOPEN_SOURCE 600
+#endif
+
 #define __need_IOV_MAX
 #ifndef _POSIX_C_SOURCE
 #define _POSIX_C_SOURCE 200809L /* for timespec on solaris */
