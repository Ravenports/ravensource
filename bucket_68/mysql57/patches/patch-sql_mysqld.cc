--- sql/mysqld.cc.orig	2023-03-16 15:25:04 UTC
+++ sql/mysqld.cc
@@ -3433,7 +3433,7 @@ static void push_deprecated_tls_option_n
 static int init_ssl()
 {
 #ifdef HAVE_OPENSSL
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
   CRYPTO_malloc_init();
 #else /* OPENSSL_VERSION_NUMBER < 0x10100000L */
   OPENSSL_malloc_init();
