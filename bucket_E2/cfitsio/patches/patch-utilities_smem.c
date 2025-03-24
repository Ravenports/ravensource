--- utilities/smem.c.orig	2025-03-12 01:55:53 UTC
+++ utilities/smem.c
@@ -1,7 +1,7 @@
 #include <stdio.h>
 #include <memory.h>
 #include <string.h>
-#ifdef __APPLE__
+#ifndef __linux__
 #include <stdlib.h>
 #else
 #include <malloc.h>
