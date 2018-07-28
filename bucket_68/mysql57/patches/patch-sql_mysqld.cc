--- sql/mysqld.cc.orig	2018-06-08 09:56:29 UTC
+++ sql/mysqld.cc
@@ -3408,7 +3408,7 @@ static int init_ssl()
 {
 #ifdef HAVE_OPENSSL
 #ifndef HAVE_YASSL
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
   CRYPTO_malloc_init();
 #else /* OPENSSL_VERSION_NUMBER < 0x10100000L */
   OPENSSL_malloc_init();
