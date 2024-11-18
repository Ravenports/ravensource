--- exp_clib.c.orig	2018-02-02 19:15:52 UTC
+++ exp_clib.c
@@ -8,6 +8,7 @@ would appreciate credit if this program
 */
 
 #include "expect_cf.h"
+#include "exp_command.h"
 #include <stdio.h>
 #include <setjmp.h>
 #ifdef HAVE_INTTYPES_H
