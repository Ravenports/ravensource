--- src/lj_ccallback.c.orig	2026-04-15 02:49:48 UTC
+++ src/lj_ccallback.c
@@ -20,6 +20,7 @@
 #include "lj_mcode.h"
 #include "lj_trace.h"
 #include "lj_vm.h"
+#include "lualib.h"
 
 #if LJ_ARCH_PPC_ELFV2
 #include "lualib.h"
