--- os.hpp.orig	2023-07-19 14:39:27 UTC
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
