--- aacenc/src/tns.c.orig	2011-07-19 07:44:07 UTC
+++ aacenc/src/tns.c
@@ -20,9 +20,9 @@
 
 *******************************************************************************/
 
+#include <assert.h>
 #include "basic_op.h"
 #include "oper_32b.h"
-#include "assert.h"
 #include "aac_rom.h"
 #include "psy_const.h"
 #include "tns.h"
