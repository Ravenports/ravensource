--- imap/src/osdep/unix/ssl_unix.c.orig	2019-06-22 16:14:55 UTC
+++ imap/src/osdep/unix/ssl_unix.c
@@ -249,9 +249,7 @@ const SSL_METHOD *ssl_connect_mthd(int f
     return NIL;		/* out of range? bail out */
 
 #ifndef OPENSSL_1_1_0
-  if(client_request == SSL3_VERSION)
-     return SSLv3_client_method();
-  else if(client_request == TLS1_VERSION)
+  if(client_request == TLS1_VERSION)
      return TLSv1_client_method();
   else if(client_request == TLS1_1_VERSION)
      return TLSv1_1_client_method();
