--- lib/tsan/sanitizer_common/sanitizer_freebsd.h.orig	2023-01-17 23:40:56 UTC
+++ lib/tsan/sanitizer_common/sanitizer_freebsd.h
@@ -19,8 +19,7 @@
 // x86-64 FreeBSD 9.2 and older define 'ucontext_t' incorrectly in
 // 32-bit mode.
 #if SANITIZER_FREEBSD && (SANITIZER_WORDSIZE == 32)
-#include <osreldate.h>
-#if __FreeBSD_version <= 902001  // v9.2
+#if 0
 #include <link.h>
 #include <sys/param.h>
 #include <ucontext.h>
