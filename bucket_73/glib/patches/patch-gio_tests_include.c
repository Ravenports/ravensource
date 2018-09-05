--- glib/tests/include.c.orig	2018-08-30 17:12:09 UTC
+++ glib/tests/include.c
@@ -3,6 +3,7 @@
 #define _POSIX_C_SOURCE 199309L
 #undef _GNU_SOURCE
 #undef _XOPEN_SOURCE
+#include <sys/types.h>
 #include <pthread.h>
 #include <glib.h>
 
