--- WWW/Library/Implementation/HTParse.c.orig	2016-11-24 15:29:50 UTC
+++ WWW/Library/Implementation/HTParse.c
@@ -23,8 +23,7 @@
 #endif
 
 #ifdef USE_IDNA
-#include <idna.h>
-#include <idn-free.h>
+#include <idn2.h>
 #endif
 
 #define HEX_ESCAPE '%'
