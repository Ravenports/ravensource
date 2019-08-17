--- configure.cmake.orig	2019-06-25 10:23:30 UTC
+++ configure.cmake
@@ -670,6 +670,7 @@ int main(int ac, char **av)
 HAVE_SYS_GETTID)
 
 # Check for pthread_getthreadid_np()
+set(CMAKE_REQUIRED_LIBRARIES pthread)
 CHECK_C_SOURCE_COMPILES("
 #include <pthread_np.h>
 int main(int ac, char **av)
@@ -678,6 +679,7 @@ int main(int ac, char **av)
   return (tid != 0 ? 0 : 1);
 }"
 HAVE_PTHREAD_GETTHREADID_NP)
+set(CMAKE_REQUIRED_LIBRARIES "")
 
 # Check for pthread_threadid_np()
 CHECK_C_SOURCE_COMPILES("
