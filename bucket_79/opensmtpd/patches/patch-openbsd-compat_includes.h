--- openbsd-compat/includes.h.orig	2020-05-21 19:06:04 UTC
+++ openbsd-compat/includes.h
@@ -65,6 +65,7 @@
 #endif
 
 #include <openssl/opensslv.h> /* For OPENSSL_VERSION_NUMBER */
+#include <openssl/ssl.h>
 
 #include "defines.h"
 
