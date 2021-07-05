--- src/jrd/os/posix/unix.cpp.orig	2021-05-29 15:05:06 UTC
+++ src/jrd/os/posix/unix.cpp
@@ -56,6 +56,17 @@
 #include <linux/fs.h>
 #endif
 
+#if defined FREEBSD
+#include <sys/disk.h>
+#define BLKGETSIZE64 DIOCGMEDIASIZE
+#define BLKGETSIZE DIOCGMEDIASIZE
+#define BLKSSZGET DIOCGSECTORSIZE
+#endif
+
+#if defined DRAGONFLY
+#include <sys/diskslice.h>
+#endif
+
 #endif //SUPPORT_RAW_DEVICES
 
 #include "../jrd/jrd.h"
@@ -495,7 +506,7 @@ ULONG PIO_get_number_of_pages(const jrd_
 // Looks like any OS needs own ioctl() to determine raw device size
 #undef HAS_RAW_SIZE
 
-#ifdef LINUX
+#if defined LINUX || defined FREEBSD
 #ifdef BLKGETSIZE64
 		if (ioctl(file->fil_desc, BLKGETSIZE64, &length) != 0)
 #endif /*BLKGETSIZE64*/
@@ -514,6 +525,16 @@ ULONG PIO_get_number_of_pages(const jrd_
 #define HAS_RAW_SIZE
 #endif /*LINUX*/
 
+#if defined DRAGONFLY
+		{
+			struct partinfo pi;
+			if (ioctl(file->fil_desc, DIOCGPART, &pi) != 0)
+				unix_error("ioctl(DIOCGPART)", file, isc_io_access_err);
+			length = pi.media_size;
+		}
+#define HAS_RAW_SIZE
+#endif /*DRAGONFLY*/
+
 #ifndef HAS_RAW_SIZE
 error: Raw device support for your OS is missing. Fix it or turn off raw device support.
 #endif
