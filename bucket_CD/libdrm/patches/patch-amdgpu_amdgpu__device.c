--- amdgpu/amdgpu_device.c.orig	2026-04-27 15:47:19 UTC
+++ amdgpu/amdgpu_device.c
@@ -218,7 +218,12 @@ static int _amdgpu_device_initialize(int
 			return r;
 		}
 		if ((flag_auth) && (!flag_authexist)) {
+#ifdef F_DUPFD_CLOEXEC
 			dev->flink_fd = fcntl(fd, F_DUPFD_CLOEXEC, 0);
+#else
+			dev->flink_fd = fcntl(fd, F_DUPFD, 0);
+			fcntl(dev->flink_fd, F_SETFD, FD_CLOEXEC);
+#endif
 		}
 		*major_version = dev->major_version;
 		*minor_version = dev->minor_version;
@@ -252,7 +257,12 @@ static int _amdgpu_device_initialize(int
 		goto cleanup;
 	}
 
+#ifdef F_DUPFD_CLOEXEC
 	dev->fd = fcntl(fd, F_DUPFD_CLOEXEC, 0);
+#else
+	dev->fd = fcntl(fd, F_DUPFD, 0);
+	fcntl(dev->fd, F_SETFD, FD_CLOEXEC);
+#endif
 	dev->flink_fd = dev->fd;
 	dev->major_version = version->version_major;
 	dev->minor_version = version->version_minor;
