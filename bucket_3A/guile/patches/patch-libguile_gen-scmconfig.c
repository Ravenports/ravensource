--- libguile/gen-scmconfig.c.orig	2019-08-02 12:41:06 UTC
+++ libguile/gen-scmconfig.c
@@ -143,6 +143,9 @@
 
 #include "gen-scmconfig.h"
 
+#if defined __FreeBSD__ || defined __DragonFly__
+#define _ANSI_SOURCE
+#endif
 #define pf printf
 
 int
