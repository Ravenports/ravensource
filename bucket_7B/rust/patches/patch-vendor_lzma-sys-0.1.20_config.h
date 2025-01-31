--- vendor/lzma-sys-0.1.20/config.h.orig	2025-01-27 23:20:59 UTC
+++ vendor/lzma-sys-0.1.20/config.h
@@ -35,7 +35,6 @@
     // change to `MYTHREAD_WIN95` if targeting Windows XP or earlier
     #define MYTHREAD_VISTA 1
 #else
-    #define _POSIX_C_SOURCE 199506L
     #define MYTHREAD_POSIX 1
 #endif
 
