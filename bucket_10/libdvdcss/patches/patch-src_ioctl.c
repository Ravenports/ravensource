--- src/ioctl.c.orig	2025-09-23 08:43:53 UTC
+++ src/ioctl.c
@@ -1076,6 +1076,18 @@ int ioctl_ReadCPRMMediaId(int i_fd,int *
     if (i_ret == 0)
         memcpy(p_buffer, dvd.buffer, sizeof(dvd.bufferLength));
 
+#elif defined(HAVE_BSD_DVD_STRUCT)
+
+    i_ret = -1;
+
+#elif defined(HAVE_LINUX_DVD_STRUCT)  // NetBSD
+
+    i_ret = -1;
+
+#elif defined(SOLARIS_USCSI)  // OmniOS
+
+    i_ret = -1;
+
 #else
 #   error "DVD ioctls are unavailable on this system"
 
@@ -1178,6 +1190,18 @@ int ioctl_ReadCPRMMKBPack(int i_fd, int
     }
     return i_ret;
 
+#elif defined(HAVE_BSD_DVD_STRUCT)
+
+    i_ret = -1;
+
+#elif defined(HAVE_LINUX_DVD_STRUCT)  // NetBSD
+
+    i_ret = -1;
+
+#elif defined(SOLARIS_USCSI)  // OmniOS
+
+    i_ret = -1;
+
 #else
 #   error "DVD ioctls are unavailable on this system"
 
