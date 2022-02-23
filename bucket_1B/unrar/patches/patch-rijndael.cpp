--- rijndael.cpp.orig	2022-02-22 11:55:53 UTC
+++ rijndael.cpp
@@ -3,6 +3,8 @@
  **************************************************************************/
 #include "rar.hpp"
 
+#ifndef OPENSSL_AES
+
 #ifdef USE_SSE
 #include <wmmintrin.h>
 #endif
@@ -75,6 +77,7 @@ inline void Copy128(byte *dest,const byt
 #endif
 }
 
+#endif // OPENSSL_AES
 
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // API
@@ -82,14 +85,35 @@ inline void Copy128(byte *dest,const byt
 
 Rijndael::Rijndael()
 {
+#ifndef OPENSSL_AES
   if (S5[0]==0)
     GenerateTables();
+#endif // OPENSSL_AES
   CBCMode = true; // Always true for RAR.
 }
 
 
 void Rijndael::Init(bool Encrypt,const byte *key,uint keyLen,const byte * initVector)
 {
+#ifdef OPENSSL_AES
+  const EVP_CIPHER *cipher;
+  switch(keyLen)
+  {
+    case 128:
+      cipher = EVP_aes_128_cbc();
+      break;
+    case 192:
+      cipher = EVP_aes_192_cbc();
+      break;
+    case 256:
+      cipher = EVP_aes_256_cbc();
+      break;
+  }
+
+  EVP_CIPHER_CTX_init(&ctx);
+  EVP_CipherInit_ex(&ctx, cipher, NULL, key, initVector, Encrypt);
+  EVP_CIPHER_CTX_set_padding(&ctx, 0);
+#else // OPENSSL_AES
 #ifdef USE_SSE
   // Check SSE here instead of constructor, so if object is a part of some
   // structure memset'ed before use, this variable is not lost.
@@ -139,6 +163,7 @@ void Rijndael::Init(bool Encrypt,const b
 
   if(!Encrypt)
     keyEncToDec();
+#endif // OPENSSL_AES
 }
 
 void Rijndael::blockEncrypt(const byte *input,size_t inputLen,byte *outBuffer)
@@ -146,6 +171,11 @@ void Rijndael::blockEncrypt(const byte *
   if (inputLen <= 0)
     return;
 
+#ifdef OPENSSL_AES
+  int outLen;
+  EVP_CipherUpdate(&ctx, outBuffer, &outLen, input, inputLen);
+  return;
+#else // OPENSSL_AES
   size_t numBlocks = inputLen/16;
 #ifdef USE_SSE
   if (AES_NI)
@@ -204,6 +234,7 @@ void Rijndael::blockEncrypt(const byte *
     input += 16;
   }
   Copy128(m_initVector,prevBlock);
+#endif // OPENSSL_AES
 }
 
 
@@ -245,6 +276,11 @@ void Rijndael::blockDecrypt(const byte *
   if (inputLen <= 0)
     return;
 
+#ifdef OPENSSL_AES
+  int outLen;
+  EVP_CipherUpdate(&ctx, outBuffer, &outLen, input, inputLen);
+  return;
+#else // OPENSSL_AES
   size_t numBlocks=inputLen/16;
 #ifdef USE_SSE
   if (AES_NI)
@@ -307,6 +343,8 @@ void Rijndael::blockDecrypt(const byte *
   }
 
   memcpy(m_initVector,iv,16);
+
+#endif // OPENSSL_AES
 }
 
 
@@ -342,7 +380,7 @@ void Rijndael::blockDecryptSSE(const byt
 }
 #endif
 
-
+#ifndef OPENSSL_AES
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // ALGORITHM
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
@@ -471,7 +509,7 @@ void Rijndael::GenerateTables()
     U1[b][0]=U2[b][1]=U3[b][2]=U4[b][3]=T5[I][0]=T6[I][1]=T7[I][2]=T8[I][3]=gmul(b,0xe);
   }
 }
-
+#endif // OPENSSL_AES
 
 #if 0
 static void TestRijndael();
