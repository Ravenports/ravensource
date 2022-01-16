--- src/video/kmsdrm/SDL_kmsdrmvideo.c.orig	2022-01-08 02:29:52 UTC
+++ src/video/kmsdrm/SDL_kmsdrmvideo.c
@@ -71,6 +71,10 @@ static SDL_bool openbsd69orgreater = SDL
 #define EGL_PLATFORM_GBM_MESA 0x31D7
 #endif
 
+#ifndef O_CLOEXEC
+#define O_CLOEXEC 0
+#endif
+
 static int
 check_modestting(int devindex)
 {
