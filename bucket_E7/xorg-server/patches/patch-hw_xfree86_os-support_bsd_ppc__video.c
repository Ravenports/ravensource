--- hw/xfree86/os-support/bsd/ppc_video.c.orig	2019-11-22 23:44:19 UTC
+++ hw/xfree86/os-support/bsd/ppc_video.c
@@ -79,7 +79,11 @@ xf86DisableIO()
 {
 
     if (ioBase != MAP_FAILED) {
+#if defined(__FreeBSD__)
+        munmap(__DEVOLATILE(unsigned char *, ioBase), 0x10000);
+#else
         munmap(__UNVOLATILE(ioBase), 0x10000);
+#endif
         ioBase = MAP_FAILED;
     }
 }
