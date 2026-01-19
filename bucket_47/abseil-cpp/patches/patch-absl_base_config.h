--- absl/base/config.h.orig	2026-01-07 19:26:27 UTC
+++ absl/base/config.h
@@ -375,6 +375,7 @@ static_assert(ABSL_INTERNAL_INLINE_NAMES
 #ifdef ABSL_HAVE_MMAP
 #error ABSL_HAVE_MMAP cannot be directly set
 #elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || \
+    defined(__DragonFly__) ||                                             \
     defined(_AIX) || defined(__ros__) || defined(__asmjs__) ||            \
     defined(__EMSCRIPTEN__) || defined(__Fuchsia__) || defined(__sun) ||  \
     defined(__myriad2__) || defined(__HAIKU__) || defined(__OpenBSD__) || \
@@ -391,6 +392,7 @@ static_assert(ABSL_INTERNAL_INLINE_NAMES
 #ifdef ABSL_HAVE_PTHREAD_GETSCHEDPARAM
 #error ABSL_HAVE_PTHREAD_GETSCHEDPARAM cannot be directly set
 #elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || \
+    defined(__DragonFly__) ||                                             \
     defined(_AIX) || defined(__ros__) || defined(__OpenBSD__) ||          \
     defined(__NetBSD__) || defined(__VXWORKS__)
 #define ABSL_HAVE_PTHREAD_GETSCHEDPARAM 1
