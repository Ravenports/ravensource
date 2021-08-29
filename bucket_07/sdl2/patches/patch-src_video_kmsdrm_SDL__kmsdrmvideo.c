--- src/video/kmsdrm/SDL_kmsdrmvideo.c.orig	2021-07-27 14:52:29 UTC
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
