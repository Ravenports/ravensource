--- libguile/gen-scmconfig.c.orig	2018-09-22 20:51:40 UTC
+++ libguile/gen-scmconfig.c
@@ -143,6 +143,9 @@
 
 #include "gen-scmconfig.h"
 
+#if defined __FreeBSD__ || defined __DragonFly__
+#define _ANSI_SOURCE
+#endif
 #define pf printf
 
 int
