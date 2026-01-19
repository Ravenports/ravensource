--- src/ucm/main.c.orig	2026-01-13 07:12:40 UTC
+++ src/ucm/main.c
@@ -40,6 +40,10 @@
 #include <sys/wait.h>
 #include <limits.h>
 
+#if !defined(CLOCK_MONOTONIC_RAW)
+#define CLOCK_MONOTONIC_RAW CLOCK_MONOTONIC
+#endif
+
 /*
  * misc
  */
@@ -176,7 +180,11 @@ static int read_tlv_file(unsigned int **
 		err = -errno;
 		goto __fail;
 	}
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+	if (fstat(fd, &st) == -1) {
+#else
 	if (fstat64(fd, &st) == -1) {
+#endif
 		err = -errno;
 		goto __fail;
 	}
