--- os.hpp.orig	2018-06-24 15:10:31 UTC
+++ os.hpp
@@ -161,6 +161,10 @@
 #include <locale.h>
 
 
+#ifdef OPENSSL_AES
+#include <openssl/evp.h>
+#endif // OPENSSL_AES
+
 #ifdef  S_IFLNK
 #define SAVE_LINKS
 #endif
