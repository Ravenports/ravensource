--- tools/vendor/abseil-cpp/absl/base/internal/raw_logging.cc.orig	2025-01-07 11:51:24 UTC
+++ tools/vendor/abseil-cpp/absl/base/internal/raw_logging.cc
@@ -42,6 +42,7 @@
 // This preprocessor token is also defined in raw_io.cc.  If you need to copy
 // this, consider moving both to config.h instead.
 #if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || \
+    defined(__DragonFly__) || \
     defined(__Fuchsia__) || defined(__native_client__) ||               \
     defined(__OpenBSD__) || defined(__EMSCRIPTEN__) || defined(__ASYLO__)
 
