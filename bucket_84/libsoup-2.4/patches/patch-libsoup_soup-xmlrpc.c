--- libsoup/soup-xmlrpc.c.orig	2022-10-11 18:27:22 UTC
+++ libsoup/soup-xmlrpc.c
@@ -18,6 +18,7 @@
 #include <string.h>
 #include <errno.h>
 #include <libxml/tree.h>
+#include <libxml/parser.h>
 #include "soup-xmlrpc.h"
 #include "soup.h"
 
