--- src/musleep.c.orig	2022-10-03 00:01:10 UTC
+++ src/musleep.c
@@ -42,6 +42,7 @@
 #endif
 #include <sys/param.h>
 #include <sys/types.h>
+#include <string.h> /* memset() */
 #include <stdio.h> /* perror() */
 
 int usleep_new(unsigned long microSeconds)
