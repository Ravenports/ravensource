--- src/absl/base/config.h.orig	2023-01-11 14:22:54 UTC
+++ src/absl/base/config.h
@@ -414,6 +414,7 @@ static_assert(ABSL_INTERNAL_INLINE_NAMES
 #ifdef ABSL_HAVE_MMAP
 #error ABSL_HAVE_MMAP cannot be directly set
 #elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || \
+    defined(__DragonFly__) || \
     defined(_AIX) || defined(__ros__) || defined(__native_client__) ||    \
     defined(__asmjs__) || defined(__wasm__) || defined(__Fuchsia__) ||    \
     defined(__sun) || defined(__ASYLO__) || defined(__myriad2__) ||       \
@@ -429,6 +430,7 @@ static_assert(ABSL_INTERNAL_INLINE_NAMES
 #ifdef ABSL_HAVE_PTHREAD_GETSCHEDPARAM
 #error ABSL_HAVE_PTHREAD_GETSCHEDPARAM cannot be directly set
 #elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || \
+    defined(__DragonFly__) || \
     defined(_AIX) || defined(__ros__) || defined(__OpenBSD__) ||          \
     defined(__NetBSD__)
 #define ABSL_HAVE_PTHREAD_GETSCHEDPARAM 1
