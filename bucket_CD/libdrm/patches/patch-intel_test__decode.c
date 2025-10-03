--- intel/test_decode.c.orig	2025-06-08 12:27:53 UTC
+++ intel/test_decode.c
@@ -28,7 +28,13 @@
 #include <fcntl.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#ifdef __sun__
+#define errx(exitcode, format, args...) \
+	{ fprintf(stderr, format "\n", ## args); \
+	  exit(exitcode); }
+#else
 #include <err.h>
+#endif
 
 #include "libdrm_macros.h"
 #include "intel_bufmgr.h"
