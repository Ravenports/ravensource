--- os.hpp.orig	2021-12-09 19:25:18 UTC
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
