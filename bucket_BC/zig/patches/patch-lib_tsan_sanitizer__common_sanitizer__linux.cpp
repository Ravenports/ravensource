--- lib/tsan/sanitizer_common/sanitizer_linux.cpp.orig	2023-08-03 18:22:03 UTC
+++ lib/tsan/sanitizer_common/sanitizer_linux.cpp
@@ -142,7 +142,7 @@ const int FUTEX_WAKE_PRIVATE = FUTEX_WAK
 # define SANITIZER_USE_GETRANDOM 0
 #endif  // SANITIZER_LINUX && defined(__NR_getrandom)
 
-#if SANITIZER_FREEBSD && __FreeBSD_version >= 1200000
+#if SANITIZER_FREEBSD
 #  define SANITIZER_USE_GETENTROPY 1
 #else
 #  define SANITIZER_USE_GETENTROPY 0
