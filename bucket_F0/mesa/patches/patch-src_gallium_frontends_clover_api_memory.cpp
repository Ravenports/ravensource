--- src/gallium/frontends/clover/api/memory.cpp.orig	2021-04-07 16:36:56 UTC
+++ src/gallium/frontends/clover/api/memory.cpp
@@ -518,7 +518,11 @@ clSVMAlloc(cl_context d_ctx,
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
 #endif
