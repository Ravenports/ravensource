--- include/global.h.orig	2025-04-14 16:42:04 UTC
+++ include/global.h
@@ -107,7 +107,7 @@ int snd_dlclose(void *handle);
 
 
 /** \brief alloca helper macro. */
-#define __snd_alloca(ptr,type) do { *ptr = (type##_t *) alloca(type##_sizeof()); memset(*ptr, 0, type##_sizeof()); } while (0)
+#define __snd_alloca(ptr,type) do { *ptr = (type##_t *) __builtin_alloca(type##_sizeof()); memset(*ptr, 0, type##_sizeof()); } while (0)
 
 /**
  * \brief Internal structure for an async notification client handler.
