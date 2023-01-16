--- src/absl/time/internal/cctz/include/cctz/time_zone.h.orig	2023-01-11 14:22:54 UTC
+++ src/absl/time/internal/cctz/include/cctz/time_zone.h
@@ -20,6 +20,10 @@
 #ifndef ABSL_TIME_INTERNAL_CCTZ_TIME_ZONE_H_
 #define ABSL_TIME_INTERNAL_CCTZ_TIME_ZONE_H_
 
+#if defined __NetBSD__ && !defined _NETBSD_SOURCE
+#define _NETBSD_SOURCE
+#endif
+
 #include <chrono>
 #include <cstdint>
 #include <limits>
