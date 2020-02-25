--- openbsd-compat/includes.h.orig	2020-02-10 22:52:54 UTC
+++ openbsd-compat/includes.h
@@ -65,6 +65,7 @@
 #endif
 
 #include <openssl/opensslv.h> /* For OPENSSL_VERSION_NUMBER */
+#include <openssl/ssl.h>
 
 #include "defines.h"
 
