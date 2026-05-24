--- ext/socket/ipsocket.c.orig	2025-12-16 23:56:55.000000000 -0000
+++ ext/socket/ipsocket.c
@@ -10,6 +10,9 @@
 
 #include "rubysocket.h"
 #include <stdio.h>
+#if !defined(EAI_ADDRFAMILY)
+#define EAI_ADDRFAMILY 0
+#endif
 
 struct inetsock_arg
 {
