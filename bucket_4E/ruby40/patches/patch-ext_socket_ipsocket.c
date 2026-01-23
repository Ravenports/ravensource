--- ext/socket/ipsocket.c.orig	2026-01-13 02:02:40 UTC
+++ ext/socket/ipsocket.c
@@ -10,6 +10,9 @@
 
 #include "rubysocket.h"
 #include <stdio.h>
+#if !defined(EAI_ADDRFAMILY)
+#define EAI_ADDRFAMILY 0
+#endif
 
 struct inetsock_arg
 {
