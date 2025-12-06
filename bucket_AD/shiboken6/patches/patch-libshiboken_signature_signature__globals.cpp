--- libshiboken/signature/signature_globals.cpp.orig	2025-11-18 11:43:26 UTC
+++ libshiboken/signature/signature_globals.cpp
@@ -217,25 +217,19 @@ static int init_phase_2(safe_globals_str
 ////////////////////////////////////////////////////////////////////////////
 // a stack trace for linux-like platforms
 #include <cstdio>
-#if defined(__GLIBC__)
 #  include <execinfo.h>
-#endif
 #include <signal.h>
 #include <cstdlib>
 #include <unistd.h>
 
 static void handler(int sig) {
-#if defined(__GLIBC__)
     void *array[30];
     // get void *'s for all entries on the stack
     const int size = backtrace(array, 30);
 
     // print out all the frames to stderr
-#endif
     std::fprintf(stderr, "Error: signal %d:\n", sig);
-#if defined(__GLIBC__)
     backtrace_symbols_fd(array, size, STDERR_FILENO);
-#endif
     exit(1);
 }
 
