--- os.hpp.orig	2024-01-24 08:50:09 UTC
+++ os.hpp
@@ -165,6 +165,10 @@
 #endif
 #endif
 
+#ifdef OPENSSL_AES
+#include <openssl/evp.h>
+#endif // OPENSSL_AES
+
 #ifdef  S_IFLNK
 #define SAVE_LINKS
 #endif
