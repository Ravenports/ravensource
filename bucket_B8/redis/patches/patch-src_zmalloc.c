--- src/zmalloc.c.orig	2021-02-22 21:23:58 UTC
+++ src/zmalloc.c
@@ -49,20 +49,18 @@ void zlibc_free(void *ptr) {
 
 #ifdef HAVE_MALLOC_SIZE
 #define PREFIX_SIZE (0)
+#define ASSERT_NO_SIZE_OVERFLOW(sz)
 #else
 #if defined(__sun) || defined(__sparc) || defined(__sparc__)
 #define PREFIX_SIZE (sizeof(long long))
 #else
 #define PREFIX_SIZE (sizeof(size_t))
 #endif
-#endif
-
-#if PREFIX_SIZE > 0
+#include <assert.h>
 #define ASSERT_NO_SIZE_OVERFLOW(sz) assert((sz) + PREFIX_SIZE > (sz))
-#else
-#define ASSERT_NO_SIZE_OVERFLOW(sz)
 #endif
 
+
 /* Explicitly override malloc/free etc when using tcmalloc. */
 #if defined(USE_TCMALLOC)
 #define malloc(size) tc_malloc(size)
