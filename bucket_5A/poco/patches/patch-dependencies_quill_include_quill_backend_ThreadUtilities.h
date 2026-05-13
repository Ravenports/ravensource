--- dependencies/quill/include/quill/backend/ThreadUtilities.h.orig	2026-04-16 18:15:35 UTC
+++ dependencies/quill/include/quill/backend/ThreadUtilities.h
@@ -47,6 +47,10 @@
 #elif defined(__OpenBSD__)
   #include <pthread_np.h>
   #include <unistd.h>
+#elif defined(__sun)
+  #include <sys/types.h>
+  #include <sys/lwp.h>
+  #include <unistd.h>
 #else
   // linux
   #include <pthread.h>
@@ -220,6 +224,8 @@ QUILL_NODISCARD QUILL_EXPORT QUILL_ATTRI
   return static_cast<uint32_t>(lwp_gettid());
 #elif defined(__OpenBSD__)
   return static_cast<uint32_t>(getthrid());
+#elif defined(__sun)
+  return static_cast<uint32_t>(_lwp_self());
 #else
   return reinterpret_cast<uintptr_t>(pthread_self()); // (Ab)use pthread_self as a last resort option
 #endif
