--- src/util/os_memory_stdc.h.orig	2020-04-22 21:36:59 UTC
+++ src/util/os_memory_stdc.h
@@ -51,11 +51,16 @@
 static inline void *
 os_malloc_aligned(size_t size, size_t alignment)
 {
+#ifdef __sun
+   alignment = (alignment + sizeof(void*) - 1) & ~(sizeof(void*) - 1);
+   return memalign(alignment, size);
+#else
    void *ptr;
    alignment = (alignment + sizeof(void*) - 1) & ~(sizeof(void*) - 1);
    if(posix_memalign(&ptr, alignment, size) != 0)
       return NULL;
    return ptr;
+#endif
 }
 
 #define os_free_aligned(_ptr) free(_ptr)
