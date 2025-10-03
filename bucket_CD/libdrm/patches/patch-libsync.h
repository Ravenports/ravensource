define ETIME as ETIMEOUT same as done in mesa

--- libsync.h.orig	2025-06-08 12:27:53 UTC
+++ libsync.h
@@ -35,6 +35,9 @@
 #include <sys/ioctl.h>
 #include <poll.h>
 #include <unistd.h>
+#ifndef ETIME
+#define ETIME ETIMEDOUT
+#endif
 
 #if defined(__cplusplus)
 extern "C" {
@@ -53,6 +56,9 @@ struct sync_merge_data {
 	uint32_t	flags;
 	uint32_t	pad;
 };
+#ifdef __sun__
+#include <sys/ioccom.h>
+#endif
 #define SYNC_IOC_MAGIC		'>'
 #define SYNC_IOC_MERGE		_IOWR(SYNC_IOC_MAGIC, 3, struct sync_merge_data)
 #endif
