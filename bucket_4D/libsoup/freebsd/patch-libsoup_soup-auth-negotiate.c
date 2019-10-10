--- libsoup/soup-auth-negotiate.c.orig	2019-10-09 09:49:52 UTC
+++ libsoup/soup-auth-negotiate.c
@@ -13,7 +13,7 @@
 #include <string.h>
 
 #ifdef LIBSOUP_HAVE_GSSAPI
-#include <gssapi/gssapi.h>
+#include <gssapi/gssapi_krb5.h>
 #endif /* LIBSOUP_HAVE_GSSAPI */
 
 #include "soup-auth-negotiate.h"
