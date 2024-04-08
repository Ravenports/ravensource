--- tools/rpmuncompress.c.orig	2024-04-08 13:03:35.425860000 +0200
+++ tools/rpmuncompress.c	2024-04-08 13:03:54.620219000 +0200
@@ -5,6 +5,7 @@
 #include <errno.h>
 #include <stdio.h>
 #include <string.h>
+#include <sys/wait.h>
 
 #include <rpm/rpmcli.h>
 #include <rpm/rpmstring.h>
