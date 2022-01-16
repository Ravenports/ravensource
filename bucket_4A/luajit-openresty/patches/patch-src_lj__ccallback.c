--- src/lj_ccallback.c.orig	2022-01-11 05:27:47 UTC
+++ src/lj_ccallback.c
@@ -20,6 +20,7 @@
 #include "lj_mcode.h"
 #include "lj_trace.h"
 #include "lj_vm.h"
+#include "lualib.h"
 
 #if LJ_ARCH_PPC_ELFV2
 #include "lualib.h"
