--- third-party/mimalloc/src/alloc-override.c.orig	2023-07-26 10:40:11 UTC
+++ third-party/mimalloc/src/alloc-override.c
@@ -232,7 +232,7 @@ extern "C" {
   // Forward Posix/Unix calls as well
   void*  reallocf(void* p, size_t newsize) MI_FORWARD2(mi_reallocf,p,newsize)
   size_t malloc_size(const void* p)        MI_FORWARD1(mi_usable_size,p)
-  #if !defined(__ANDROID__) && !defined(__FreeBSD__)
+  #if !defined(__ANDROID__) && !defined(__FreeBSD__) && !defined(__DragonFly__)
   size_t malloc_usable_size(void *p)       MI_FORWARD1(mi_usable_size,p)
   #else
   size_t malloc_usable_size(const void *p) MI_FORWARD1(mi_usable_size,p)
