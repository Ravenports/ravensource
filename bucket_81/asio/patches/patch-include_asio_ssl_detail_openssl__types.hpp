--- include/asio/ssl/detail/openssl_types.hpp.orig	2022-08-13 01:20:41 UTC
+++ include/asio/ssl/detail/openssl_types.hpp
@@ -20,15 +20,15 @@
 #if defined(ASIO_USE_WOLFSSL)
 # include <wolfssl/options.h>
 #endif // defined(ASIO_USE_WOLFSSL)
-#include <openssl/conf.h>
-#include <openssl/ssl.h>
+#include </__PREFIX__/__SSLVARIANT__/include/openssl/conf.h>
+#include </__PREFIX__/__SSLVARIANT__/include/openssl/ssl.h>
 #if !defined(OPENSSL_NO_ENGINE)
-# include <openssl/engine.h>
+# include </__PREFIX__/__SSLVARIANT__/include/openssl/engine.h>
 #endif // !defined(OPENSSL_NO_ENGINE)
-#include <openssl/dh.h>
-#include <openssl/err.h>
-#include <openssl/rsa.h>
-#include <openssl/x509.h>
-#include <openssl/x509v3.h>
+#include </__PREFIX__/__SSLVARIANT__/include/openssl/dh.h>
+#include </__PREFIX__/__SSLVARIANT__/include/openssl/err.h>
+#include </__PREFIX__/__SSLVARIANT__/include/openssl/rsa.h>
+#include </__PREFIX__/__SSLVARIANT__/include/openssl/x509.h>
+#include </__PREFIX__/__SSLVARIANT__/include/openssl/x509v3.h>
 
 #endif // ASIO_SSL_DETAIL_OPENSSL_TYPES_HPP
