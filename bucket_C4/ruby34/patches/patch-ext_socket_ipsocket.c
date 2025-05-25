--- ext/socket/ipsocket.c.orig	2025-05-14 03:11:06 UTC
+++ ext/socket/ipsocket.c
@@ -10,6 +10,9 @@
 
 #include "rubysocket.h"
 #include <stdio.h>
+#if !defined(EAI_ADDRFAMILY)
+#define EAI_ADDRFAMILY 0
+#endif
 
 struct inetsock_arg
 {
