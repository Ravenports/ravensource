--- extension/inplace.c.orig	2024-03-03 18:41:43 UTC
+++ extension/inplace.c
@@ -27,12 +27,14 @@
 #include <config.h>
 #endif
 
+#if !(defined __sun__ && (__STDC_VERSION__ - 0 >= 199901L))
 #ifndef _XOPEN_SOURCE
 # define _XOPEN_SOURCE 1
 #endif
 #ifndef _XOPEN_SOURCE_EXTENDED
 # define _XOPEN_SOURCE_EXTENDED 1
 #endif
+#endif /* __sun__ check */
 
 #include <stdio.h>
 #include <assert.h>
