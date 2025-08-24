--- lib/krad/packet.c.orig	2025-08-20 19:44:32 UTC
+++ lib/krad/packet.c
@@ -33,6 +33,10 @@
 
 #include <arpa/inet.h>
 
+#ifndef ENODATA
+#define ENODATA ENOATTR
+#endif
+
 typedef unsigned char uchar;
 
 /* RFC 2865 */
