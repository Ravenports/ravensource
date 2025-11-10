--- src/ioctl.c.orig	2025-11-10 00:23:53 UTC
+++ src/ioctl.c
@@ -1076,6 +1076,10 @@ int ioctl_ReadCPRMMediaId(int i_fd,int *
     if (i_ret == 0)
         memcpy(p_buffer, dvd.buffer, sizeof(dvd.bufferLength));
 
+#elif defined(HAVE_BSD_DVD_STRUCT)
+
+    i_ret = -1;
+
 #else
 #   error "DVD ioctls are unavailable on this system"
 
@@ -1178,6 +1182,10 @@ int ioctl_ReadCPRMMKBPack(int i_fd, int
     }
     return i_ret;
 
+#elif defined(HAVE_BSD_DVD_STRUCT)
+
+    i_ret = -1;
+
 #else
 #   error "DVD ioctls are unavailable on this system"
 
