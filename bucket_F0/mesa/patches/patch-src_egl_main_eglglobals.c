--- src/egl/main/eglglobals.c.orig	2020-07-22 20:47:01 UTC
+++ src/egl/main/eglglobals.c
@@ -139,7 +139,7 @@ _eglPointerIsDereferencable(void *p)
 {
    uintptr_t addr = (uintptr_t) p;
    const long page_size = getpagesize();
-#ifdef HAVE_MINCORE
+#if defined(HAVE_MINCORE) && !defined(__DragonFly__)
    unsigned char valid = 0;
 
    if (p == NULL)
