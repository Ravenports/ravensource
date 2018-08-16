--- amdgpu/amdgpu_device.c.orig	2018-08-01 01:45:18 UTC
+++ amdgpu/amdgpu_device.c
@@ -206,7 +206,12 @@ int amdgpu_device_initialize(int fd,
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
@@ -240,7 +245,12 @@ int amdgpu_device_initialize(int fd,
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
