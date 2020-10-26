--- rijndael.cpp.orig	2020-10-22 08:48:23 UTC
+++ rijndael.cpp
@@ -7,6 +7,8 @@
  ***************************************************************************/
 #include "rar.hpp"
 
+#ifndef OPENSSL_AES
+
 #ifdef USE_SSE
 #include <wmmintrin.h>
 #endif
@@ -56,6 +58,7 @@ inline void Copy128(byte *dest,const byt
 #endif
 }
 
+#endif // OPENSSL_AES
 
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // API
@@ -63,14 +66,35 @@ inline void Copy128(byte *dest,const byt
 
 Rijndael::Rijndael()
 {
+#ifndef OPENSSL_AES
   if (S[0]==0)
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
@@ -120,6 +144,7 @@ void Rijndael::Init(bool Encrypt,const b
 
   if(!Encrypt)
     keyEncToDec();
+#endif // OPENSSL_AES
 }
 
 void Rijndael::blockEncrypt(const byte *input,size_t inputLen,byte *outBuffer)
@@ -127,6 +152,11 @@ void Rijndael::blockEncrypt(const byte *
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
@@ -185,6 +215,7 @@ void Rijndael::blockEncrypt(const byte *
     input += 16;
   }
   Copy128(m_initVector,prevBlock);
+#endif // OPENSSL_AES
 }
 
 
@@ -226,6 +257,11 @@ void Rijndael::blockDecrypt(const byte *
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
@@ -288,6 +324,8 @@ void Rijndael::blockDecrypt(const byte *
   }
 
   memcpy(m_initVector,iv,16);
+
+#endif // OPENSSL_AES
 }
 
 
@@ -323,7 +361,7 @@ void Rijndael::blockDecryptSSE(const byt
 }
 #endif
 
-
+#ifndef OPENSSL_AES
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // ALGORITHM
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
@@ -463,7 +501,7 @@ void Rijndael::GenerateTables()
     U1[b][0]=U2[b][1]=U3[b][2]=U4[b][3]=T5[i][0]=T6[i][1]=T7[i][2]=T8[i][3]=FFmul0e(b);
   }
 }
-
+#endif // OPENSSL_AES
 
 #if 0
 static void TestRijndael();
