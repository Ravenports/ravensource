--- libmariadb/libmariadb/secure/openssl_crypt.c.orig	2025-04-28 13:44:23 UTC
+++ libmariadb/libmariadb/secure/openssl_crypt.c
@@ -36,8 +36,6 @@ static const EVP_MD *ma_hash_get_algorit
     return EVP_sha384();
   case MA_HASH_SHA512:
     return EVP_sha512();
-  case MA_HASH_RIPEMD160:
-    return EVP_ripemd160();
   default:
     return NULL;
   }
