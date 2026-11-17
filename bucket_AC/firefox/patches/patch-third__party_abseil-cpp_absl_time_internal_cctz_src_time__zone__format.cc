--- third_party/abseil-cpp/absl/time/internal/cctz/src/time_zone_format.cc.orig	2026-11-07 02:40:20 UTC
+++ third_party/abseil-cpp/absl/time/internal/cctz/src/time_zone_format.cc
@@ -21,8 +21,7 @@
 #endif
 
 #if HAS_STRPTIME
-#if !defined(_XOPEN_SOURCE) && !defined(__FreeBSD__) && \
-    !defined(__OpenBSD__) && !defined(__APPLE__)
+#if !defined(_XOPEN_SOURCE) && defined(__linux__)
 #define _XOPEN_SOURCE 500  // Exposes definitions for SUSv2 (UNIX 98).
 #endif
 #endif
