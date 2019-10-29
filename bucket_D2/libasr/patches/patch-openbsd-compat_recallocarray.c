--- openbsd-compat/recallocarray.c.orig	2019-09-28 14:09:47 UTC
+++ openbsd-compat/recallocarray.c
@@ -79,7 +79,11 @@ recallocarray(void *ptr, size_t oldnmemb
 	} else
 		memcpy(newptr, ptr, newsize);
 
+#ifdef HAVE_EXPLICIT_BZERO
 	explicit_bzero(ptr, oldsize);
+#else
+	bzero(ptr, oldsize);
+#endif
 	free(ptr);
 
 	return newptr;
