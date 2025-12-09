on omnios:
./psi/interp.c: In function 'do_call_operator':
./psi/interp.c:89:5: error: implicit declaration of function '__assert_c99' [-Wimplicit-function-declaration]
   89 |     assert(e_stack.p >= e_stack.bot - 1 && e_stack.p < e_stack.top + 1);
      |     ^~~~~~
gmake[3]: *** [psi/int.mak:1909: soobj/interp.o] Error 1

avoid the asserts completely.

--- psi/interp.c.orig	2025-09-09 09:36:39 UTC
+++ psi/interp.c
@@ -50,7 +50,6 @@
 #include "store.h"
 #include "gpcheck.h"
 #define FORCE_ASSERT_CHECKING 1
-#define DEBUG_TRACE_PS_OPERATORS 1
 #include "assert_.h"
 
 /*
