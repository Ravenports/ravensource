--- boost/thread/pthread/thread_data.hpp.orig	2024-04-11 18:48:06 UTC
+++ boost/thread/pthread/thread_data.hpp
@@ -32,6 +32,7 @@
 # endif
 #endif
 
+#include <limits.h>
 #include <pthread.h>
 #include <unistd.h>
 
