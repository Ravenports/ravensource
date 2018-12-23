--- wddx.c.orig	2017-08-01 17:36:48 UTC
+++ wddx.c
@@ -22,6 +22,10 @@
 #include "config.h"
 #endif
 
+#ifdef HAVE_CONFIG_H
+# include "config.h"
+#endif
+
 #include "php.h"
 
 #if HAVE_WDDX
@@ -260,7 +264,7 @@ static void release_wddx_packet_rsrc(zen
 
 #include "ext/session/php_session.h"
 
-#if HAVE_PHP_SESSION && !defined(COMPILE_DL_SESSION)
+#if HAVE_PHP_SESSION
 /* {{{ PS_SERIALIZER_ENCODE_FUNC
  */
 PS_SERIALIZER_ENCODE_FUNC(wddx)
@@ -335,7 +339,7 @@ PHP_MINIT_FUNCTION(wddx)
 {
 	le_wddx = zend_register_list_destructors_ex(release_wddx_packet_rsrc, NULL, "wddx", module_number);
 
-#if HAVE_PHP_SESSION && !defined(COMPILE_DL_SESSION)
+#if HAVE_PHP_SESSION
 	php_session_register_serializer("wddx",
 									PS_SERIALIZER_ENCODE_NAME(wddx),
 									PS_SERIALIZER_DECODE_NAME(wddx));
@@ -350,7 +354,7 @@ PHP_MINIT_FUNCTION(wddx)
 PHP_MINFO_FUNCTION(wddx)
 {
 	php_info_print_table_start();
-#if HAVE_PHP_SESSION && !defined(COMPILE_DL_SESSION)
+#if HAVE_PHP_SESSION
 	php_info_print_table_header(2, "WDDX Support", "enabled" );
 	php_info_print_table_row(2, "WDDX Session Serializer", "enabled" );
 #else
