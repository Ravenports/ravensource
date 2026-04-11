--- dependencies/quill/include/quill/backend/BackendUtilities.h.orig	2026-03-24 10:38:30 UTC
+++ dependencies/quill/include/quill/backend/BackendUtilities.h
@@ -39,6 +39,11 @@
   #include <pthread_np.h>
   #include <sched.h>
   #include <unistd.h>
+#elif defined(__sun)
+  #include <unistd.h>
+  #include <sys/types.h>
+  #include <sys/processor.h>
+  #include <sys/procset.h>
 #else
   // linux, anything else
   #include <pthread.h>
@@ -99,6 +104,8 @@ QUILL_ATTRIBUTE_COLD inline void set_cpu
   // OpenBSD doesn't support CPU affinity, so we'll use a placeholder
   (void)cpu_id;
   auto const err = 0; // Assume success
+  #elif defined(__sun)
+  auto const err = processor_bind(P_LWPID, P_MYID, static_cast<processorid_t>(cpu_id), NULL);
   #else
   cpu_set_t cpuset;
   CPU_ZERO(&cpuset);
