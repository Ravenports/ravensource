--- configure.cmake.orig	2019-09-20 08:30:51 UTC
+++ configure.cmake
@@ -660,6 +660,7 @@ int main(int ac, char **av)
 HAVE_SYS_GETTID)
 
 # Check for pthread_getthreadid_np()
+set(CMAKE_REQUIRED_LIBRARIES pthread)
 CHECK_C_SOURCE_COMPILES("
 #include <pthread_np.h>
 int main(int ac, char **av)
@@ -668,6 +669,7 @@ int main(int ac, char **av)
   return (tid != 0 ? 0 : 1);
 }"
 HAVE_PTHREAD_GETTHREADID_NP)
+set(CMAKE_REQUIRED_LIBRARIES "")
 
 # Check for pthread_threadid_np()
 CHECK_C_SOURCE_COMPILES("
