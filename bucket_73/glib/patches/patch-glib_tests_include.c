--- glib/tests/include.c.orig	2024-12-11 22:21:22 UTC
+++ glib/tests/include.c
@@ -1,8 +1,11 @@
 /* Test case for bug 659866 */
 
+#ifndef __sun
 #define _POSIX_C_SOURCE 199309L
 #undef _GNU_SOURCE
 #undef _XOPEN_SOURCE
+#endif
+#include <sys/types.h>
 #include <pthread.h>
 #include <glib.h>
 
