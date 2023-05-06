--- src/ucm/main.c.orig	2023-05-04 07:16:16 UTC
+++ src/ucm/main.c
@@ -176,7 +176,11 @@ static int read_tlv_file(unsigned int **
 		err = -errno;
 		return err;
 	}
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+	if (fstat(fd, &st) == -1) {
+#else
 	if (fstat64(fd, &st) == -1) {
+#endif
 		err = -errno;
 		goto __fail;
 	}
