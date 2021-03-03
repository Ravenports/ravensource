--- src/gallium/frontends/clover/api/memory.cpp.orig	2021-01-29 18:33:19 UTC
+++ src/gallium/frontends/clover/api/memory.cpp
@@ -457,7 +457,11 @@ clSVMAlloc(cl_context d_ctx,
       void *ptr = nullptr;
       if (alignment < sizeof(void*))
          alignment = sizeof(void*);
+#ifdef __sun
+      ptr = memalign(alignment, size);
+#else
       posix_memalign(&ptr, alignment, size);
+#endif
       return ptr;
    }
 
