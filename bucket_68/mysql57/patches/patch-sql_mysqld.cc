--- sql/mysqld.cc.orig	2021-03-26 06:58:52 UTC
+++ sql/mysqld.cc
@@ -3428,7 +3428,7 @@ int warn_self_signed_ca()
 static int init_ssl()
 {
 #ifdef HAVE_OPENSSL
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
   CRYPTO_malloc_init();
 #else /* OPENSSL_VERSION_NUMBER < 0x10100000L */
   OPENSSL_malloc_init();
