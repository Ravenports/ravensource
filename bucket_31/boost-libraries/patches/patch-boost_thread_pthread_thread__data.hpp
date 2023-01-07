--- boost/thread/pthread/thread_data.hpp.orig	2022-12-08 01:02:48 UTC
+++ boost/thread/pthread/thread_data.hpp
@@ -32,6 +32,7 @@
 # endif
 #endif
 
+#include <limits.h>
 #include <pthread.h>
 #include <unistd.h>
 
