--- libsoup/soup-xmlrpc-old.c.orig	2022-10-11 18:27:22 UTC
+++ libsoup/soup-xmlrpc-old.c
@@ -12,6 +12,7 @@
 #include <string.h>
 
 #include <libxml/tree.h>
+#include <libxml/parser.h>
 
 #include "soup-xmlrpc-old.h"
 #include "soup.h"
