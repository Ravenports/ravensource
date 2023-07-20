--- sal/osl/unx/thread.cxx.orig	2023-07-07 16:45:40 UTC
+++ sal/osl/unx/thread.cxx
@@ -39,6 +39,10 @@
 #define pthread_setname_np pthread_set_name_np
 #endif
 #endif
+#ifdef __DragonFly__
+#include <pthread_np.h>
+#define pthread_setname_np pthread_set_name_np
+#endif
 #include <config_options.h>
 #include <o3tl/safeint.hxx>
 #include <osl/thread.h>
