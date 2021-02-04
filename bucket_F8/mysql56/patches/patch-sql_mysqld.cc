--- sql/mysqld.cc.orig	2021-01-05 10:19:59 UTC
+++ sql/mysqld.cc
@@ -4375,7 +4375,7 @@ static void openssl_lock(int mode, opens
 static int init_ssl()
 {
 #ifdef HAVE_OPENSSL
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
   CRYPTO_malloc_init();
 #else /* OPENSSL_VERSION_NUMBER < 0x10100000L */
   OPENSSL_malloc_init();
