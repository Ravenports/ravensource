--- os.hpp.orig	2023-09-17 15:27:44 UTC
+++ os.hpp
@@ -173,6 +173,10 @@
 #include <locale.h>
 
 
+#ifdef OPENSSL_AES
+#include <openssl/evp.h>
+#endif // OPENSSL_AES
+
 #ifdef  S_IFLNK
 #define SAVE_LINKS
 #endif
