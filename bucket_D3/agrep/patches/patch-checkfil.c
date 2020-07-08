--- checkfil.c.orig	2016-10-22 12:40:44 UTC
+++ checkfil.c
@@ -10,7 +10,7 @@
 #include <ctype.h>
 #include <fcntl.h>
 #include <sys/types.h>
-#ifdef __APPLE__
+#if defined __APPLE__ || defined __DragonFly__ || defined __FreeBSD__
     #include <sys/stat.h>
 #endif
 #include <errno.h>
