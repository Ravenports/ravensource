--- os.hpp.orig	2025-03-20 10:03:14 UTC
+++ os.hpp
@@ -170,6 +170,10 @@
 #endif
 #endif
 
+#ifdef OPENSSL_AES
+#include <openssl/evp.h>
+#endif // OPENSSL_AES
+
 #ifdef  S_IFLNK
 #define SAVE_LINKS
 #endif
