--- src/util/os_memory_aligned.h.orig	2025-12-04 06:02:48 UTC
+++ src/util/os_memory_aligned.h
@@ -42,11 +42,16 @@
 static inline void *
 os_malloc_aligned(size_t size, size_t alignment)
 {
+#ifdef __sun__
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
