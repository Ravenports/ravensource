--- src/vulkan/wsi/wsi_common_drm.c.orig	2023-03-08 18:37:09 UTC
+++ src/vulkan/wsi/wsi_common_drm.c
@@ -29,17 +29,24 @@
 #include "vk_device.h"
 #include "vk_physical_device.h"
 #include "vk_util.h"
+#if defined(__linux__)
 #include "drm-uapi/drm_fourcc.h"
 
 #include <errno.h>
 #include <linux/dma-buf.h>
 #include <linux/sync_file.h>
+#else
+#include "drm-uapi/dma-buf.h
+
+#include <errno.h>
+#endif
 #include <time.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <xf86drm.h>
 
+#if defined(__linux__)
 struct dma_buf_export_sync_file_wsi {
    __u32 flags;
    __s32 fd;
@@ -52,6 +59,7 @@ struct dma_buf_import_sync_file_wsi {
 
 #define DMA_BUF_IOCTL_EXPORT_SYNC_FILE_WSI   _IOWR(DMA_BUF_BASE, 2, struct dma_buf_export_sync_file_wsi)
 #define DMA_BUF_IOCTL_IMPORT_SYNC_FILE_WSI   _IOW(DMA_BUF_BASE, 3, struct dma_buf_import_sync_file_wsi)
+#endif
 
 static VkResult
 wsi_dma_buf_export_sync_file(int dma_buf_fd, int *sync_file_fd)
@@ -61,11 +69,19 @@ wsi_dma_buf_export_sync_file(int dma_buf
    if (no_dma_buf_sync_file)
       return VK_ERROR_FEATURE_NOT_PRESENT;
 
+#if defined(__linux__)
    struct dma_buf_export_sync_file_wsi export = {
       .flags = DMA_BUF_SYNC_RW,
       .fd = -1,
    };
    int ret = drmIoctl(dma_buf_fd, DMA_BUF_IOCTL_EXPORT_SYNC_FILE_WSI, &export);
+#else
+   struct dma_buf_export_sync_file export = {
+      .flags = DMA_BUF_SYNC_RW,
+      .fd = -1,
+   };
+   int ret = drmIoctl(dma_buf_fd, DMA_BUF_IOCTL_EXPORT_SYNC_FILE, &export);
+#endif
    if (ret) {
       if (errno == ENOTTY || errno == EBADF || errno == ENOSYS) {
          no_dma_buf_sync_file = true;
@@ -88,11 +104,19 @@ wsi_dma_buf_import_sync_file(int dma_buf
    if (no_dma_buf_sync_file)
       return VK_ERROR_FEATURE_NOT_PRESENT;
 
+#if defined(__linux__)
    struct dma_buf_import_sync_file_wsi import = {
       .flags = DMA_BUF_SYNC_RW,
       .fd = sync_file_fd,
    };
    int ret = drmIoctl(dma_buf_fd, DMA_BUF_IOCTL_IMPORT_SYNC_FILE_WSI, &import);
+#else
+   struct dma_buf_import_sync_file import = {
+      .flags = DMA_BUF_SYNC_RW,
+      .fd = sync_file_fd,
+   };
+   int ret = drmIoctl(dma_buf_fd, DMA_BUF_IOCTL_IMPORT_SYNC_FILE, &import);
+#endif
    if (ret) {
       if (errno == ENOTTY || errno == EBADF || errno == ENOSYS) {
          no_dma_buf_sync_file = true;
