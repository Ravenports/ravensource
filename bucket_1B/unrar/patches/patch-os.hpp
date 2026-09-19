--- os.hpp.orig	2026-06-27 11:35:31 UTC
+++ os.hpp
@@ -174,6 +174,10 @@
 #endif
 #endif
 
+#ifdef OPENSSL_AES
+#include <openssl/evp.h>
+#endif // OPENSSL_AES
+
 #ifdef  S_IFLNK
 #define SAVE_LINKS
 #endif
