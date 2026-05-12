--- os.hpp.orig	2026-04-27 08:23:52 UTC
+++ os.hpp
@@ -174,6 +174,10 @@
 #endif
 #endif
 
+#ifdef OPENSSL_AES
+#include <openssl/evp.h>
+#endif // OPENSSL_AES
+
 #ifdef  S_IFLNK
 #define SAVE_LINKS
 #endif
