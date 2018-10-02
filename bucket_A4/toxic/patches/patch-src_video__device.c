--- src/video_device.c.orig	2018-02-27 23:46:56 UTC
+++ src/video_device.c
@@ -37,7 +37,7 @@
 #include <sys/stat.h>
 #include <sys/mman.h>
 #include <fcntl.h>
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #include <linux/videodev2.h>
 #else
 #include <sys/videoio.h>
@@ -69,7 +69,7 @@ typedef struct VideoDevice {
     void *cb_data;                          /* Data to be passed to callback */
     int32_t friend_number;                  /* ToxAV friend number */
 
-#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
     int fd;                                 /* File descriptor of video device selected/opened */
     struct v4l2_format fmt;
     struct VideoBuffer *buffers;
@@ -136,7 +136,7 @@ static void yuv420tobgr(uint16_t width,
     }
 }
 
-#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
 static void yuv422to420(uint8_t *plane_y, uint8_t *plane_u, uint8_t *plane_v,
                         uint8_t *input, uint16_t width, uint16_t height)
 {
@@ -724,7 +724,7 @@ void *video_thread_poll (void *arg) // T
                     XFlush(device->x_display);
                     free(img_data);
 
-#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
 
                     if ( -1 == xioctl(device->fd, VIDIOC_QBUF, &buf) ) {
                         unlock;
@@ -787,7 +787,7 @@ VideoDeviceError close_video_device(Vide
             XCloseDisplay(device->x_display);
             pthread_mutex_destroy(device->mutex);
 
-#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
             free(device->buffers);
 #endif /* __linux__ / BSD */
 
