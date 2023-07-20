--- rijndael.hpp.orig	2023-07-19 14:39:28 UTC
+++ rijndael.hpp
@@ -12,6 +12,9 @@
 class Rijndael
 { 
   private:
+#ifdef OPENSSL_AES
+    EVP_CIPHER_CTX ctx;
+#else // OPENSSL_AES
 #ifdef USE_SSE
     void blockEncryptSSE(const byte *input,size_t numBlocks,byte *outBuffer);
     void blockDecryptSSE(const byte *input, size_t numBlocks, byte *outBuffer);
@@ -31,6 +34,7 @@ class Rijndael
     void keySched(byte key[_MAX_KEY_COLUMNS][4]);
     void keyEncToDec();
     void GenerateTables();
+#endif // OPENSSL_AES
 
     // RAR always uses CBC, but we may need to turn it off when calling
     // this code from other archive formats with CTR and other modes.
