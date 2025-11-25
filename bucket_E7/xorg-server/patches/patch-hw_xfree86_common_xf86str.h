--- hw/xfree86/common/xf86str.h.orig	2025-10-28 17:14:33 UTC
+++ hw/xfree86/common/xf86str.h
@@ -249,7 +249,7 @@ typedef struct _DriverRec {
  */
 
 /* Tolerate prior #include <linux/input.h> */
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #undef BUS_NONE
 #undef BUS_PCI
 #undef BUS_SBUS
