--- src/lib/OpenEXRCore/internal_posix_file_impl.h.orig	2026-11-20 20:27:19 UTC
+++ src/lib/OpenEXRCore/internal_posix_file_impl.h
@@ -32,6 +32,10 @@ _Static_assert (
     "OpenEXRCore needs a 64-bit off_t: compile with -D_FILE_OFFSET_BITS=64");
 #endif
 
+#ifndef O_CLOEXEC
+#define O_CLOEXEC 0
+#endif
+
 #if defined __USE_UNIX98 || defined __USE_XOPEN2K8 ||                          \
     (defined(_XOPEN_VERSION) && _XOPEN_VERSION >= 400)
 #    define CAN_USE_PREAD 1
