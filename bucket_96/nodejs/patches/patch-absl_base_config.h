--- deps/v8/third_party/abseil-cpp/absl/base/config.h.orig	2024-05-15 12:35:05 UTC
+++ deps/v8/third_party/abseil-cpp/absl/base/config.h
@@ -412,6 +412,7 @@ static_assert(ABSL_INTERNAL_INLINE_NAMES
 #ifdef ABSL_HAVE_MMAP
 #error ABSL_HAVE_MMAP cannot be directly set
 #elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) ||    \
+    defined(__DragonFly__) ||                                                \
     defined(_AIX) || defined(__ros__) || defined(__native_client__) ||       \
     defined(__asmjs__) || defined(__EMSCRIPTEN__) || defined(__Fuchsia__) || \
     defined(__sun) || defined(__ASYLO__) || defined(__myriad2__) ||          \
@@ -427,6 +428,7 @@ static_assert(ABSL_INTERNAL_INLINE_NAMES
 #ifdef ABSL_HAVE_PTHREAD_GETSCHEDPARAM
 #error ABSL_HAVE_PTHREAD_GETSCHEDPARAM cannot be directly set
 #elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || \
+    defined(__DragonFly__) ||                                             \
     defined(_AIX) || defined(__ros__) || defined(__OpenBSD__) ||          \
     defined(__NetBSD__) || defined(__VXWORKS__)
 #define ABSL_HAVE_PTHREAD_GETSCHEDPARAM 1
