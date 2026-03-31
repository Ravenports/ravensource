--- src/malloc.c.orig	2018-11-23 06:32:49 UTC
+++ src/malloc.c
@@ -163,9 +163,6 @@ my_strdup(char *src)
 #ifndef _WIN32
 /* added by daved */
 #include <sys/types.h>
-#undef malloc
-
-void *malloc();
 
 /* Allocate an N-byte block of memory from the heap.
 If N is zero, allocate a 1-byte block.  */
@@ -179,4 +176,4 @@ rpl_malloc(size_t n)
 	}
 	return malloc(n);
 }
-#endif
\ No newline at end of file
+#endif
