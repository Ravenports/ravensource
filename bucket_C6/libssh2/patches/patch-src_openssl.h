Hard-disabled RIPEMD, it may not be in all ssl libraries

--- src/openssl.h.orig	2021-05-14 21:36:06 UTC
+++ src/openssl.h
@@ -94,11 +94,7 @@
 # define LIBSSH2_MD5 1
 #endif
 
-#ifdef OPENSSL_NO_RIPEMD
 # define LIBSSH2_HMAC_RIPEMD 0
-#else
-# define LIBSSH2_HMAC_RIPEMD 1
-#endif
 
 #define LIBSSH2_HMAC_SHA256 1
 #define LIBSSH2_HMAC_SHA512 1
