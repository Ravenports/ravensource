--- src/mpc.h.orig	2026-04-14 12:42:32 UTC
+++ src/mpc.h
@@ -21,6 +21,7 @@ along with this program. If not, see htt
 #ifndef __MPC_H
 #define __MPC_H
 
+#include <stdio.h> /* for FILE */
 #include <stdint.h>
 #include "gmp.h"
 #include "mpfr.h"
