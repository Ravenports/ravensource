--- bin/cbsdsh/jail.c.orig	2023-03-10 21:18:40 UTC
+++ bin/cbsdsh/jail.c
@@ -1,7 +1,7 @@
 #include <sys/param.h>
 #include <sys/jail.h>
 
-#ifdef __DragonFly__
+#if defined(_DragonFly__) || defined(__MidnightBSD__)
 
 #include <sys/types.h>
 #include <sys/sysctl.h>
