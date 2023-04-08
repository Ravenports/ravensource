--- sal/osl/unx/thread.cxx.orig	2023-03-24 16:53:38 UTC
+++ sal/osl/unx/thread.cxx
@@ -37,6 +37,10 @@
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
