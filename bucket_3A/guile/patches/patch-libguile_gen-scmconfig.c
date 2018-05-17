--- libguile/gen-scmconfig.c.orig	2017-11-06 09:08:20 UTC
+++ libguile/gen-scmconfig.c
@@ -138,6 +138,9 @@
 
 #include <libguile/gen-scmconfig.h>
 
+#if defined __FreeBSD__ || defined __DragonFly__
+#define _ANSI_SOURCE
+#endif
 #include <stdio.h>
 #include <string.h>
 
