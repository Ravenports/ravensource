--- lib/librdkafka-2.3.0/src/rd.h.orig	2024-03-21 15:26:52 UTC
+++ lib/librdkafka-2.3.0/src/rd.h
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
