--- os.hpp.orig	2022-02-22 11:55:53 UTC
+++ os.hpp
@@ -168,6 +168,10 @@
 #include <locale.h>
 
 
+#ifdef OPENSSL_AES
+#include <openssl/evp.h>
+#endif // OPENSSL_AES
+
 #ifdef  S_IFLNK
 #define SAVE_LINKS
 #endif
