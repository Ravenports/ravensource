--- bin/cbsdsh/src/jail.c.orig	2026-04-12 13:46:35 UTC
+++ bin/cbsdsh/src/jail.c
@@ -1,7 +1,7 @@
 #include <sys/param.h>
 #include <sys/jail.h>
 
-#ifdef __DragonFly__
+#if defined(__DragonFly__) || defined(__MidnightBSD__)
 
 #include <sys/types.h>
 #include <sys/sysctl.h>
