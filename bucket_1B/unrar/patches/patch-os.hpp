--- os.hpp.orig	2025-11-20 08:19:13 UTC
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
