--- media/ffvpx/libavutil/cpu.c.orig	2025-04-12 05:13:46 UTC
+++ media/ffvpx/libavutil/cpu.c
@@ -49,6 +49,13 @@
 #include <unistd.h>
 #endif
 
+#if defined(__DragonFly__)
+#undef HAVE_GETAUXVAL
+#undef HAVE_ELF_AUX_INFO
+#define HAVE_GETAUXVAL 0
+#define HAVE_ELF_AUX_INFO 0
+#endif
+
 #if HAVE_GETAUXVAL || HAVE_ELF_AUX_INFO
 #include <sys/auxv.h>
 #endif
