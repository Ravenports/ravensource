--- src/pipewire/thread.c.orig	2024-02-02 13:09:07 UTC
+++ src/pipewire/thread.c
@@ -6,6 +6,9 @@
 #include <unistd.h>
 #include <sys/types.h>
 #include <pthread.h>
+#ifdef __FreeBSD__
+#include <pthread_np.h>
+#endif
 
 #include <spa/utils/dict.h>
 #include <spa/utils/defs.h>
