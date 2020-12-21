--- src/egl/main/eglglobals.c.orig	2020-12-16 18:43:56 UTC
+++ src/egl/main/eglglobals.c
@@ -135,7 +135,7 @@ _eglPointerIsDereferencable(void *p)
 {
    uintptr_t addr = (uintptr_t) p;
    const long page_size = getpagesize();
-#ifdef HAVE_MINCORE
+#if defined(HAVE_MINCORE) && !defined(__DragonFly__)
    unsigned char valid = 0;
 
    if (p == NULL)
