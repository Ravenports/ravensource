--- config/ssl/openssl/wrappers.c.orig	2023-09-11 14:03:24 UTC
+++ config/ssl/openssl/wrappers.c
@@ -115,7 +115,7 @@ unsigned long __aws_OpenSSL_version_num(
 
 void __aws_OPENSSL_thread_stop(void)
 {
-  OPENSSL_thread_stop();
+  __aws_OPENSSL_thread_stop();
 }
 
 const char * __aws_OpenSSL_version(int t)
