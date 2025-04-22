* check for EVFILT_USER, if missing disable kqueue (necessary on NetBSD 9.x)

--- configure.cmake.orig	2025-03-31 08:00:22 UTC
+++ configure.cmake
@@ -183,11 +183,6 @@ ENDIF()
 #
 INCLUDE (CheckIncludeFiles)
 
-IF(FREEBSD)
-  # On FreeBSD some includes, e.g. sasl/sasl.h, is in /usr/local/include
-  LIST(APPEND CMAKE_REQUIRED_INCLUDES "/usr/local/include")
-ENDIF()
-
 CHECK_INCLUDE_FILES (alloca.h HAVE_ALLOCA_H)
 CHECK_INCLUDE_FILES (arpa/inet.h HAVE_ARPA_INET_H)
 CHECK_INCLUDE_FILES (dlfcn.h HAVE_DLFCN_H)
@@ -241,6 +236,7 @@ CHECK_FUNCTION_EXISTS (fcntl HAVE_FCNTL)
 CHECK_FUNCTION_EXISTS (fdatasync HAVE_FDATASYNC)
 CHECK_SYMBOL_EXISTS(fdatasync "unistd.h" HAVE_DECL_FDATASYNC)
 CHECK_FUNCTION_EXISTS (fedisableexcept HAVE_FEDISABLEEXCEPT)
+CHECK_FUNCTION_EXISTS (ffsll HAVE_FFSLL)
 CHECK_FUNCTION_EXISTS (fsync HAVE_FSYNC)
 CHECK_FUNCTION_EXISTS (gethrtime HAVE_GETHRTIME)
 CHECK_FUNCTION_EXISTS (getpass HAVE_GETPASS)
@@ -301,6 +297,7 @@ CHECK_SYMBOL_EXISTS(TIOCGWINSZ "sys/ioct
 CHECK_SYMBOL_EXISTS(FIONREAD "sys/ioctl.h" FIONREAD_IN_SYS_IOCTL)
 CHECK_SYMBOL_EXISTS(FIONREAD "sys/filio.h" FIONREAD_IN_SYS_FILIO)
 CHECK_SYMBOL_EXISTS(MADV_DONTDUMP "sys/mman.h" HAVE_MADV_DONTDUMP)
+CHECK_SYMBOL_EXISTS(EVFILT_USER "sys/event.h" HAVE_EVFILT_USER)
 CHECK_CXX_SOURCE_COMPILES(
 "#include <sys/types.h>
  #include <sys/stat.h>
@@ -333,6 +330,14 @@ ELSEIF(HAVE_TIMER_CREATE AND HAVE_TIMER_
   SET(HAVE_POSIX_TIMERS 1 CACHE INTERNAL "Have POSIX timer-related functions")
 ENDIF()
 
+IF (NOT HAVE_EVFILT_USER)
+  SET(HAVE_KQUEUE 0)
+  SET(HAVE_KQUEUE_TIMERS 0)
+  IF(HAVE_TIMER_CREATE AND HAVE_TIMER_SETTIME)
+    SET(HAVE_POSIX_TIMERS 1 CACHE INTERNAL "Have POSIX timer-related functions")
+  ENDIF()
+ENDIF()
+
 IF(NOT HAVE_POSIX_TIMERS AND NOT HAVE_KQUEUE_TIMERS AND NOT WIN32)
   MESSAGE(FATAL_ERROR "No mysys timer support detected!")
 ENDIF()
@@ -564,6 +569,7 @@ int main(int ac, char **av)
 HAVE_SYS_GETTID)
 
 # Check for pthread_getthreadid_np()
+set(CMAKE_REQUIRED_LIBRARIES pthread)
 CHECK_C_SOURCE_COMPILES("
 #include <pthread_np.h>
 int main(int ac, char **av)
@@ -572,6 +578,7 @@ int main(int ac, char **av)
   return (tid != 0 ? 0 : 1);
 }"
 HAVE_PTHREAD_GETTHREADID_NP)
+set(CMAKE_REQUIRED_LIBRARIES "")
 
 # Check for pthread_threadid_np()
 CHECK_C_SOURCE_COMPILES("
