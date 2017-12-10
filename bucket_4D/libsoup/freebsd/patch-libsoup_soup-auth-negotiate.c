--- libsoup/soup-auth-negotiate.c.orig	2017-12-09 08:28:36.594795000 +0100
+++ libsoup/soup-auth-negotiate.c	2017-12-09 08:28:59.421891000 +0100
@@ -13,7 +13,7 @@
 #include <string.h>
 
 #ifdef LIBSOUP_HAVE_GSSAPI
-#include <gssapi/gssapi.h>
+#include <gssapi/gssapi_krb5.h>
 #endif /* LIBSOUP_HAVE_GSSAPI */
 
 #include "soup-auth-negotiate.h"
