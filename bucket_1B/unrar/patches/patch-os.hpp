--- os.hpp.orig	2024-04-25 08:03:38 UTC
+++ os.hpp
@@ -166,6 +166,10 @@
 #endif
 #endif
 
+#ifdef OPENSSL_AES
+#include <openssl/evp.h>
+#endif // OPENSSL_AES
+
 #ifdef  S_IFLNK
 #define SAVE_LINKS
 #endif
