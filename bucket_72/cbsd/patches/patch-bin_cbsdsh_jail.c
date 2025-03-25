--- bin/cbsdsh/jail.c.orig	2025-03-10 09:42:46 UTC
+++ bin/cbsdsh/jail.c
@@ -1,7 +1,7 @@
 #include <sys/param.h>
 #include <sys/jail.h>
 
-#ifdef __DragonFly__
+#if defined(__DragonFly__) || defined(__MidnightBSD__)
 
 #include <sys/types.h>
 #include <sys/sysctl.h>
