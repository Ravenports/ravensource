--- src/util/os_memory_stdc.h.orig	2019-10-21 16:53:58 UTC
+++ src/util/os_memory_stdc.h
@@ -53,11 +53,16 @@
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
