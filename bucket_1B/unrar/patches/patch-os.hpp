--- os.hpp.orig	2018-03-11 06:24:39 UTC
+++ os.hpp
@@ -152,6 +152,10 @@
 #include <locale.h>
 
 
+#ifdef OPENSSL_AES
+#include <openssl/evp.h>
+#endif // OPENSSL_AES
+
 #ifdef  S_IFLNK
 #define SAVE_LINKS
 #endif
