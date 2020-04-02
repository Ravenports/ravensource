- Without sysinfo() fall back to sysconf()
- Define ETIME if missing

--- src/intel/vulkan/anv_device.c.orig	2020-04-01 21:27:14 UTC
+++ src/intel/vulkan/anv_device.c
@@ -25,7 +25,9 @@
 #include <stdbool.h>
 #include <string.h>
 #include <sys/mman.h>
+#ifdef __GLIBC__
 #include <sys/sysinfo.h>
+#endif
 #include <unistd.h>
 #include <fcntl.h>
 #include <xf86drm.h>
@@ -66,6 +68,10 @@ DRI_CONF_END;
  */
 #define MAX_DEBUG_MESSAGE_LENGTH    4096
 
+#ifndef ETIME
+#define ETIME ETIMEDOUT
+#endif
+
 static void
 compiler_debug_log(void *data, const char *fmt, ...)
 {
@@ -103,10 +109,15 @@ static uint64_t
 anv_compute_heap_size(int fd, uint64_t gtt_size)
 {
    /* Query the total ram from the system */
+#ifdef __GLIBC__
    struct sysinfo info;
    sysinfo(&info);
 
    uint64_t total_ram = (uint64_t)info.totalram * (uint64_t)info.mem_unit;
+#else
+   uint64_t total_ram = sysconf(_SC_PHYS_PAGES) * sysconf(_SC_PAGE_SIZE);
+#endif
+
 
    /* We don't want to burn too much ram with the GPU.  If the user has 4GiB
     * or less, we use at most half.  If they have more than 4GiB, we use 3/4.
