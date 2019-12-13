--- boost/thread/pthread/thread_data.hpp.orig	2019-12-10 00:20:01 UTC
+++ boost/thread/pthread/thread_data.hpp
@@ -32,6 +32,7 @@
 # endif
 #endif
 
+#include <limits.h>
 #include <pthread.h>
 #include <unistd.h>
 
@@ -57,9 +58,7 @@ namespace boost
 #else
           std::size_t page_size = ::sysconf( _SC_PAGESIZE);
 #endif
-#if PTHREAD_STACK_MIN > 0
           if (size<PTHREAD_STACK_MIN) size=PTHREAD_STACK_MIN;
-#endif
           size = ((size+page_size-1)/page_size)*page_size;
           int res = pthread_attr_setstacksize(&val_, size);
           BOOST_VERIFY(!res && "pthread_attr_setstacksize failed");
