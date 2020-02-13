--- openbsd-compat/includes.h.orig	2019-11-05 19:08:33 UTC
+++ openbsd-compat/includes.h
@@ -65,6 +65,7 @@
 #endif
 
 #include <openssl/opensslv.h> /* For OPENSSL_VERSION_NUMBER */
+#include <openssl/ssl.h>
 
 #include "defines.h"
 
