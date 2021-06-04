--- src/libaccountsservice/act-user.c.orig	2019-04-23 17:16:09.000000000 +0200
+++ src/libaccountsservice/act-user.c	2021-06-03 15:51:50.971983000 +0200
@@ -26,8 +26,6 @@
 #include <sys/stat.h>
 #include <unistd.h>
 
-#include <crypt.h>
-
 #include <glib.h>
 #include <glib/gi18n.h>
 #include <gio/gio.h>
