--- include/sound/uapi/asound.h.orig	2020-02-19 09:35:39 UTC
+++ include/sound/uapi/asound.h
@@ -24,6 +24,9 @@
 #ifndef __SOUND_ASOUND_H
 #define __SOUND_ASOUND_H
 
+#ifdef __DragonFly__
+#include <sys/time.h>
+#endif
 #if defined(__KERNEL__) || defined(__linux__)
 #include <linux/types.h>
 #include <asm/byteorder.h>
