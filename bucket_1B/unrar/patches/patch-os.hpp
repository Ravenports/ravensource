--- os.hpp.orig	2026-02-01 18:19:00 UTC
+++ os.hpp
@@ -173,6 +173,10 @@
 #endif
 #endif
 
+#ifdef OPENSSL_AES
+#include <openssl/evp.h>
+#endif // OPENSSL_AES
+
 #ifdef  S_IFLNK
 #define SAVE_LINKS
 #endif
