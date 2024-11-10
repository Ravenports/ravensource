--- os.hpp.orig	2024-11-05 12:23:24 UTC
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
