--- sql/mysqld.cc.orig	2019-01-25 22:33:03 UTC
+++ sql/mysqld.cc
@@ -4580,7 +4580,7 @@ static int warn_self_signed_ca() {
 
 static PSI_memory_key key_memory_openssl = PSI_NOT_INSTRUMENTED;
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if defined(LIBRESSL_VERSION_NUMBER) || OPENSSL_VERSION_NUMBER < 0x10100000L
 #define FILE_LINE_ARGS
 #else
 #define FILE_LINE_ARGS , const char *, int
@@ -4597,7 +4597,7 @@ static void my_openssl_free(void *ptr FI
 
 static void init_ssl() {
 #ifdef HAVE_OPENSSL
-#if !defined(HAVE_WOLFSSL) && !defined(__sun)
+#if !defined(HAVE_WOLFSSL) && !defined(__sun) && !defined(LIBRESSL_VERSION_NUMBER)
 #if defined(HAVE_PSI_MEMORY_INTERFACE)
   static PSI_memory_info all_openssl_memory[] = {
       {&key_memory_openssl, "openssl_malloc", 0, 0,
@@ -4617,7 +4617,7 @@ static void init_ssl() {
 
 static int init_ssl_communication() {
 #ifdef HAVE_OPENSSL
-#ifndef HAVE_WOLFSSL
+#if !defined(HAVE_WOLFSSL) && !defined(LIBRESSL_VERSION_NUMBER)
   char ssl_err_string[OPENSSL_ERROR_LENGTH] = {'\0'};
   int ret_fips_mode = set_fips_mode(opt_ssl_fips_mode, ssl_err_string);
   if (ret_fips_mode != 1) {
@@ -9039,7 +9039,7 @@ bool mysqld_get_one_option(int optid,
         One can disable SSL later by using --skip-ssl or --ssl=0.
       */
       opt_use_ssl = true;
-#ifdef HAVE_WOLFSSL
+#if defined(HAVE_WOLFSSL) || defined(LIBRESSL_VERSION_NUMBER)
       /* crl has no effect in wolfSSL. */
       opt_ssl_crl = NULL;
       opt_ssl_crlpath = NULL;
