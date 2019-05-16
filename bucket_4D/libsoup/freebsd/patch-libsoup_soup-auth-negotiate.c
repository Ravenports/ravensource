--- libsoup/soup-auth-negotiate.c.orig	2019-05-15 13:36:29 UTC
+++ libsoup/soup-auth-negotiate.c
@@ -13,7 +13,7 @@
 #include <string.h>
 
 #ifdef LIBSOUP_HAVE_GSSAPI
-#include <gssapi/gssapi.h>
+#include <gssapi/gssapi_krb5.h>
 #endif /* LIBSOUP_HAVE_GSSAPI */
 
 #include "soup-auth-negotiate.h"
