--- os.hpp.orig	2021-11-15 10:54:09 UTC
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
