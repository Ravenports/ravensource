--- lib/roles/raw-file/ops-raw-file.c.orig	2026-07-26 14:15:43 UTC
+++ lib/roles/raw-file/ops-raw-file.c
@@ -27,6 +27,9 @@
 #if !defined(WIN32) && !defined(_WIN32)
 #include <sys/ioctl.h>
 #endif
+#if defined(__sun)
+#include <sys/filio.h>
+#endif
 
 static lws_handling_result_t
 rops_handle_POLLIN_raw_file(struct lws_context_per_thread *pt, struct lws *wsi,
