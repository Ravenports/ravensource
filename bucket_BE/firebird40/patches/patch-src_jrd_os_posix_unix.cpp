--- src/jrd/os/posix/unix.cpp.orig	2021-12-21 10:19:50 UTC
+++ src/jrd/os/posix/unix.cpp
@@ -56,6 +56,15 @@
 #include <linux/fs.h>
 #endif
 
+#if defined DRAGONFLY
+#include <sys/diskslice.h>
+#elif defined FREEBSD
+#include <sys/disk.h>
+#define BLKGETSIZE64 DIOCGMEDIASIZE
+#define BLKGETSIZE DIOCGMEDIASIZE
+#define BLKSSZGET DIOCGSECTORSIZE
+#endif
+
 #endif //SUPPORT_RAW_DEVICES
 
 #include "../jrd/jrd.h"
@@ -495,7 +504,15 @@ ULONG PIO_get_number_of_pages(const jrd_
 // Looks like any OS needs own ioctl() to determine raw device size
 #undef HAS_RAW_SIZE
 
-#ifdef LINUX
+#if defined DRAGONFLY
+		{
+			struct partinfo pi;
+			if (ioctl(file->fil_desc, DIOCGPART, &pi) != 0)
+				unix_error("ioctl(DIOCGPART)", file, isc_io_access_err);
+			length = pi.media_size;
+		}
+#define HAS_RAW_SIZE
+#elif defined LINUX || defined FREEBSD
 #ifdef BLKGETSIZE64
 		if (ioctl(file->fil_desc, BLKGETSIZE64, &length) != 0)
 #endif /*BLKGETSIZE64*/
