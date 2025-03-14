--- cd-discid.c.orig	2013-05-14 09:02:00 UTC
+++ cd-discid.c
@@ -23,6 +23,10 @@
 #include <fcntl.h>
 #include <sys/ioctl.h>
 
+#if defined(__DragonFly__) || defined(__FreeBSD__)
+#include <arpa/inet.h>
+#endif
+
 #if defined(linux)
 #include <linux/cdrom.h>
 #define cdte_track_address      cdte_addr.lba
@@ -46,7 +50,7 @@
 
 /* __FreeBSD_kernel__ is needed for properly compiling on Debian GNU/kFreeBSD
    Look at http://glibc-bsd.alioth.debian.org/porting/PORTING for more info */
-#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
 #include <sys/cdio.h>
 #define CDROM_LBA               CD_LBA_FORMAT    /* first frame is 0 */
 #define CD_MSF_OFFSET           150              /* MSF offset of first frame */
@@ -260,12 +264,12 @@ int main(int argc, char *argv[])
 	/* release file handle */
 	close(drive);
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 	TocEntry[i].cdte_track_address = ntohl(TocEntry[i].cdte_track_address);
 #endif
 
 	for (i = 0; i < last; i++) {
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 		TocEntry[i].cdte_track_address = ntohl(TocEntry[i].cdte_track_address);
 #endif
 		cksum += cddb_sum((TocEntry[i].cdte_track_address + CD_MSF_OFFSET) / CD_FRAMES);
