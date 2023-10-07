--- os.hpp.orig	2023-10-03 07:53:45 UTC
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
