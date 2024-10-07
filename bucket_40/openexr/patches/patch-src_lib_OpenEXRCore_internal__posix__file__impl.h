--- src/lib/OpenEXRCore/internal_posix_file_impl.h.orig	2024-03-25 18:27:30 UTC
+++ src/lib/OpenEXRCore/internal_posix_file_impl.h
@@ -21,6 +21,10 @@
 #include <stdlib.h>
 #include <string.h>
 
+#ifndef O_CLOEXEC
+#define O_CLOEXEC 0
+#endif
+
 #if defined __USE_UNIX98 || defined __USE_XOPEN2K8 ||                          \
     (defined(_XOPEN_VERSION) && _XOPEN_VERSION >= 400)
 #    define CAN_USE_PREAD 1
