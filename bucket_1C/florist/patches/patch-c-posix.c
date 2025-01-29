--- c-posix.c.orig	2023-03-02 16:00:46 UTC
+++ c-posix.c
@@ -59,6 +59,7 @@
 #include <stdarg.h>
 #include <string.h>
 #include <stdlib.h>
+#include <ctype.h>
 #include "confsrc/config.h"
 
 #ifdef __hpux__
@@ -722,6 +723,25 @@ typedef struct siginfo {
 
 /* sigevent must precede aiocb
  */
+#if defined(__DragonFly__)
+/*
+ * union _sigev_info {
+ *  int   sigev_signo;
+ *  int   sigev_notify_kqueue;
+ *  void *sigev_notify_attributes;
+ * };
+ * sizeof(union _sigev_info) = sizeof(int)
+ * Use "int" rather than fooling with union
+ * For simplicity, The Ada part is only going to list sigev_signo
+ * as the other two elements of the union are unused.
+ */
+  GT1(sigevent, 1)
+  GT2(sigev_notify, int)
+  GT2(sigev_signo, int)
+  GT2(sigev_value, union sigval)
+  GT2(sigev_notify_function, void (*)(union sigval))
+  GT3
+#else  /* __DragonFly__ */
 #ifdef HAVE_struct_sigevent
   GT1(sigevent, 1)
 #else
@@ -744,6 +764,7 @@ struct sigevent {
   GT2(sigev_notify_attributes,pthread_attr_t *)
 #endif
   GT3
+#endif /* __DragonFly__ */
 
 #ifdef HAVE_struct_aiocb
   GT1(aiocb, 1)
@@ -5206,9 +5227,9 @@ void create_c() {
  */
 
 #if defined(__APPLE__)
-# define BADSIG 0
+# define FLOR_BADSIG 0
 #else
-# define BADSIG (-1)
+# define FLOR_BADSIG (-1)
 #endif
 {sigset_t set;
   int sig;
@@ -5219,7 +5240,7 @@ void create_c() {
   for (sig = 0; sig < 1024; sig++) {
     result = sigismember (&set, sig);
     if (result == 1) last_good = sig;
-    else if ((result == BADSIG) && (first_bad = -1)) first_bad = sig;
+    else if ((result == FLOR_BADSIG) && (first_bad = -1)) first_bad = sig;
   }
   if (last_good == 1023)
     printf("c-posix: WARNING: signal range estimate probably too small\n");
