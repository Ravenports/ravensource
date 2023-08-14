--- boost/thread/pthread/thread_data.hpp.orig	2023-08-08 21:02:56 UTC
+++ boost/thread/pthread/thread_data.hpp
@@ -32,6 +32,7 @@
 # endif
 #endif
 
+#include <limits.h>
 #include <pthread.h>
 #include <unistd.h>
 
