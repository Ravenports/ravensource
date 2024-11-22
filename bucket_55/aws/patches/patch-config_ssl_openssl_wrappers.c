--- config/ssl/openssl/wrappers.c.orig	2024-09-18 15:17:37 UTC
+++ config/ssl/openssl/wrappers.c
@@ -115,7 +115,7 @@ unsigned long __aws_OpenSSL_version_num(
 
 void __aws_OPENSSL_thread_stop(void)
 {
-  OPENSSL_thread_stop();
+  __aws_OPENSSL_thread_stop();
 }
 
 const char * __aws_OpenSSL_version(int t)
