--- include/global.h.orig	2024-06-10 09:18:34 UTC
+++ include/global.h
@@ -104,7 +104,7 @@ int snd_dlclose(void *handle);
 
 
 /** \brief alloca helper macro. */
-#define __snd_alloca(ptr,type) do { *ptr = (type##_t *) alloca(type##_sizeof()); memset(*ptr, 0, type##_sizeof()); } while (0)
+#define __snd_alloca(ptr,type) do { *ptr = (type##_t *) __builtin_alloca(type##_sizeof()); memset(*ptr, 0, type##_sizeof()); } while (0)
 
 /**
  * \brief Internal structure for an async notification client handler.
