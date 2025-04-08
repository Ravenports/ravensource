--- mfhdf/libsrc/h4_xdr.c.orig	2024-02-29 16:34:10 UTC
+++ mfhdf/libsrc/h4_xdr.c
@@ -36,6 +36,7 @@
  * xdr.
  */
 
+#define _NETBSD_SOURCE
 #include "nc_priv.h"
 
 /* Which header files include htonl() ? */
