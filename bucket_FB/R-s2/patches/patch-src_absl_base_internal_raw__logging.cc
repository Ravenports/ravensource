--- src/absl/base/internal/raw_logging.cc.orig	2021-09-21 13:18:13 UTC
+++ src/absl/base/internal/raw_logging.cc
@@ -37,6 +37,7 @@
 // This preprocessor token is also defined in raw_io.cc.  If you need to copy
 // this, consider moving both to config.h instead.
 #if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || \
+    defined(__DragonFly__) || \
     defined(__Fuchsia__) || defined(__native_client__) || \
     defined(__EMSCRIPTEN__) || defined(__ASYLO__)
 
