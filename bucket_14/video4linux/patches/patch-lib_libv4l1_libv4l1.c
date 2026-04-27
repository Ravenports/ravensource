--- lib/libv4l1/libv4l1.c.orig	2023-02-24 16:40:23 UTC
+++ lib/libv4l1/libv4l1.c
@@ -472,7 +472,11 @@ int v4l1_dup(int fd)
 	int index = v4l1_get_index(fd);
 
 	if (index == -1)
+#if defined(__sun)
+		return dup(fd);
+#else
 		return syscall(SYS_dup, fd);
+#endif
 
 	devices[index].open_count++;
 
