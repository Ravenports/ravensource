--- src/tinycthread.h.orig	2026-03-03 21:51:01 UTC
+++ src/tinycthread.h
@@ -109,7 +109,9 @@ extern "C" {
 #include "badthreads.h"
 
 /* Compiler-specific information */
-#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
+#if defined(__cplusplus) && __cplusplus >= 201103L
+# define TTHREAD_NORETURN [[noreturn]]
+#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
   #define TTHREAD_NORETURN _Noreturn
 #elif defined(__GNUC__)
   #define TTHREAD_NORETURN __attribute__((__noreturn__))
