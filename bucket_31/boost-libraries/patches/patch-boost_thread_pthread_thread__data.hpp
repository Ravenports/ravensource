--- boost/thread/pthread/thread_data.hpp.orig	2025-12-03 13:46:47 UTC
+++ boost/thread/pthread/thread_data.hpp
@@ -32,6 +32,7 @@
 # endif
 #endif
 
+#include <limits.h>
 #include <pthread.h>
 #include <unistd.h>
 
