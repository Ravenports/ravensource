--- dependencies/quill/include/quill/backend/ThreadUtilities.h.orig	2026-03-24 10:38:30 UTC
+++ dependencies/quill/include/quill/backend/ThreadUtilities.h
@@ -46,6 +46,10 @@
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
@@ -213,6 +217,8 @@ QUILL_NODISCARD QUILL_EXPORT QUILL_ATTRI
   return static_cast<uint32_t>(lwp_gettid());
 #elif defined(__OpenBSD__)
   return static_cast<uint32_t>(getthrid());
+#elif defined(__sun)
+  return static_cast<uint32_t>(_lwp_self());
 #else
   return reinterpret_cast<uintptr_t>(pthread_self()); // (Ab)use pthread_self as a last resort option
 #endif
