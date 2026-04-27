--- lib/libv4l2/libv4l2.c.orig	2023-02-24 16:40:23 UTC
+++ lib/libv4l2/libv4l2.c
@@ -880,7 +880,11 @@ int v4l2_dup(int fd)
 	int index = v4l2_get_index(fd);
 
 	if (index == -1)
+#if defined(__sun)
+		return dup(fd);
+#else
 		return syscall(SYS_dup, fd);
+#endif
 
 	devices[index].open_count++;
 
