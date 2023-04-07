--- src/video/kmsdrm/SDL_kmsdrmvideo.c.orig	2023-04-05 18:42:08 UTC
+++ src/video/kmsdrm/SDL_kmsdrmvideo.c
@@ -68,6 +68,10 @@ static char kmsdrm_dri_cardpath[32];
 #define EGL_PLATFORM_GBM_MESA 0x31D7
 #endif
 
+#ifndef O_CLOEXEC
+#define O_CLOEXEC 0
+#endif
+
 static int
 get_driindex(void)
 {
