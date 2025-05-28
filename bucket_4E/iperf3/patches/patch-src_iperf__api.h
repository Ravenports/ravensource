--- src/iperf_api.h.orig	2025-05-16 16:44:00 UTC
+++ src/iperf_api.h
@@ -30,6 +30,7 @@
 #include <sys/socket.h>
 #include <sys/time.h>
 #include <setjmp.h>
+#include <stdarg.h>
 #include <stdio.h>
 #include <stdint.h>
 #ifdef __cplusplus
