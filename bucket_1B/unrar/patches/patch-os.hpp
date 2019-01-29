--- os.hpp.orig	2019-01-28 10:39:42 UTC
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
