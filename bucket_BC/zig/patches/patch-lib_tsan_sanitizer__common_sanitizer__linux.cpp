--- lib/tsan/sanitizer_common/sanitizer_linux.cpp.orig	2024-04-19 21:00:35 UTC
+++ lib/tsan/sanitizer_common/sanitizer_linux.cpp
@@ -148,7 +148,7 @@ const int FUTEX_WAKE_PRIVATE = FUTEX_WAK
 # define SANITIZER_USE_GETRANDOM 0
 #endif  // SANITIZER_LINUX && defined(__NR_getrandom)
 
-#if SANITIZER_FREEBSD && __FreeBSD_version >= 1200000
+#if SANITIZER_FREEBSD
 #  define SANITIZER_USE_GETENTROPY 1
 #else
 #  define SANITIZER_USE_GETENTROPY 0
