--- aacenc/src/memalign.c.orig	2011-07-19 07:44:07 UTC
+++ aacenc/src/memalign.c
@@ -22,12 +22,12 @@
 *******************************************************************************/
 
 
-#include	"memalign.h"
 #ifdef _MSC_VER
 #include	<stddef.h>
 #else
 #include	<stdint.h>
 #endif
+#include	"memalign.h"
 
 /*****************************************************************************
 *
