--- os.hpp.orig	2021-04-07 14:41:26 UTC
+++ os.hpp
@@ -166,6 +166,10 @@
 #include <locale.h>
 
 
+#ifdef OPENSSL_AES
+#include <openssl/evp.h>
+#endif // OPENSSL_AES
+
 #ifdef  S_IFLNK
 #define SAVE_LINKS
 #endif
