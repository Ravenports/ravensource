--- os.hpp.orig	2020-01-28 15:03:59 UTC
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
