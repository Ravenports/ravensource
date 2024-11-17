--- src/aaint.h.orig	2001-04-26 14:37:31 UTC
+++ src/aaint.h
@@ -1,6 +1,8 @@
 #ifndef __AAINT_INCLUDED__
 #define __AAINT_INCLUDED__
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 
 /* Macros used for calculating fonts sizes.  */
 #define NCHARS (256*AA_NATTRS)
