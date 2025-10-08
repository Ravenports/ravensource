--- utilities/smem.c.orig	2025-09-29 02:59:26 UTC
+++ utilities/smem.c
@@ -1,7 +1,7 @@
 #include <stdio.h>
 #include <memory.h>
 #include <string.h>
-#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#ifndef __linux__
 #include <stdlib.h>
 #else
 #include <malloc.h>
