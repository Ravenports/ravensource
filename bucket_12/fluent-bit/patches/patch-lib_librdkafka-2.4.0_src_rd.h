--- lib/librdkafka-2.4.0/src/rd.h.orig	2025-01-27 14:24:05 UTC
+++ lib/librdkafka-2.4.0/src/rd.h
@@ -39,10 +39,11 @@
 #define _DARWIN_C_SOURCE /* for strlcpy, pthread_setname_np, etc */
 #endif
 
+# if defined(__NetBSD__)
+# define _XOPEN_SOURCE 600
+# endif
+
 #define __need_IOV_MAX
-#ifndef _POSIX_C_SOURCE
-#define _POSIX_C_SOURCE 200809L /* for timespec on solaris */
-#endif
 #endif
 
 #include <stdio.h>
