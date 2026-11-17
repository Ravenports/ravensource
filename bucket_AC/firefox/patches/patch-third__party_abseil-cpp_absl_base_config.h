--- third_party/abseil-cpp/absl/base/config.h.orig	2026-11-07 02:40:19 UTC
+++ third_party/abseil-cpp/absl/base/config.h
@@ -355,6 +355,7 @@ static_assert(ABSL_INTERNAL_INLINE_NAMES
 #ifdef ABSL_HAVE_PTHREAD_GETSCHEDPARAM
 #error ABSL_HAVE_PTHREAD_GETSCHEDPARAM cannot be directly set
 #elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || \
+    defined(__DragonFly__) ||                                             \
     defined(_AIX) || defined(__ros__) || defined(__OpenBSD__) ||          \
     defined(__NetBSD__) || defined(__VXWORKS__)
 #define ABSL_HAVE_PTHREAD_GETSCHEDPARAM 1
