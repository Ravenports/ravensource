The standard headers must be included before the behavior gets undefined
by the following macro definition.

--- tools/find_sts_main.c.orig	2020-08-13 00:17:09 UTC
+++ tools/find_sts_main.c
@@ -40,6 +40,8 @@
 #include <stdio.h>
 #include <math.h>
 #include <string.h>
+#include <stdlib.h>
+#include <unistd.h>
 
 /* To allow some normally const fields to manipulated during building */
 #define const
