--- src/mesa/main/imports.c.orig	2020-05-14 16:50:14 UTC
+++ src/mesa/main/imports.c
@@ -82,11 +82,15 @@ void *
 _mesa_align_malloc(size_t bytes, unsigned long alignment)
 {
 #if defined(HAVE_POSIX_MEMALIGN)
+# ifdef __sun__
+   return memalign(alignment, bytes);
+# else
    void *mem;
    int err = posix_memalign(& mem, alignment, bytes);
    if (err)
       return NULL;
    return mem;
+# endif
 #elif defined(_WIN32)
    return _aligned_malloc(bytes, alignment);
 #else
