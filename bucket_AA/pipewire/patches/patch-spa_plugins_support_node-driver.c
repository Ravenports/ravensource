--- spa/plugins/support/node-driver.c.orig	2024-02-02 13:09:07 UTC
+++ spa/plugins/support/node-driver.c
@@ -8,7 +8,7 @@
 #include <string.h>
 #include <stdio.h>
 #include <fcntl.h>
-#if !defined(__FreeBSD__) && !defined(__MidnightBSD__)
+#if !defined(__FreeBSD__) && !defined(__MidnightBSD__) && !defined(__DragonFly__)
 #include <linux/ethtool.h>
 #include <linux/sockios.h>
 #endif
