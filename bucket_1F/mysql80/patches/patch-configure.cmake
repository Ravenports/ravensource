--- configure.cmake.orig	2020-06-16 16:31:03 UTC
+++ configure.cmake
@@ -584,6 +584,7 @@ int main(int ac, char **av)
 HAVE_SYS_GETTID)
 
 # Check for pthread_getthreadid_np()
+set(CMAKE_REQUIRED_LIBRARIES pthread)
 CHECK_C_SOURCE_COMPILES("
 #include <pthread_np.h>
 int main(int ac, char **av)
@@ -592,6 +593,7 @@ int main(int ac, char **av)
   return (tid != 0 ? 0 : 1);
 }"
 HAVE_PTHREAD_GETTHREADID_NP)
+set(CMAKE_REQUIRED_LIBRARIES "")
 
 # Check for pthread_threadid_np()
 CHECK_C_SOURCE_COMPILES("
