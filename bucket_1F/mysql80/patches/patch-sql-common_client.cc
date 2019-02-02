--- sql-common/client.cc.orig	2019-01-25 22:33:03 UTC
+++ sql-common/client.cc
@@ -5623,7 +5623,7 @@ int STDCALL mysql_options(MYSQL *mysql,
 #endif
       break;
     case MYSQL_OPT_SSL_FIPS_MODE: {
-#if defined(HAVE_OPENSSL) && !defined(HAVE_WOLFSSL)
+#if defined(HAVE_OPENSSL) && !defined(HAVE_WOLFSSL) && !defined(LIBRESSL_VERSION_NUMBER)
       char ssl_err_string[OPENSSL_ERROR_LENGTH] = {'\0'};
       ENSURE_EXTENSIONS_PRESENT(&mysql->options);
       mysql->options.extension->ssl_fips_mode = *(uint *)arg;
