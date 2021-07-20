--- src/libaccountsservice/act-user.c.orig	2019-04-23 15:16:09 UTC
+++ src/libaccountsservice/act-user.c
@@ -26,7 +26,9 @@
 #include <sys/stat.h>
 #include <unistd.h>
 
+#if defined(__linux__) || defined(__sun__)
 #include <crypt.h>
+#endif
 
 #include <glib.h>
 #include <glib/gi18n.h>
