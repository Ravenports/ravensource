--- libguile/gen-scmconfig.c.orig	2023-02-10 13:16:15 UTC
+++ libguile/gen-scmconfig.c
@@ -143,6 +143,9 @@
 
 #include "gen-scmconfig.h"
 
+#if defined __FreeBSD__ || defined __DragonFly__
+#define _ANSI_SOURCE
+#endif
 #define pf printf
 
 int
