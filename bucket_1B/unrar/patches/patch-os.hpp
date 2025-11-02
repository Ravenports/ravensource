--- os.hpp.orig	2025-07-28 09:28:19 UTC
+++ os.hpp
@@ -171,6 +171,10 @@
 #endif
 #endif
 
+#ifdef OPENSSL_AES
+#include <openssl/evp.h>
+#endif // OPENSSL_AES
+
 #ifdef  S_IFLNK
 #define SAVE_LINKS
 #endif
