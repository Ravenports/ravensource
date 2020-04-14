--- plugins/preauth/pkinit/pkinit_crypto_openssl.c.orig	2020-04-13 14:52:20 UTC
+++ plugins/preauth/pkinit/pkinit_crypto_openssl.c
@@ -185,7 +185,8 @@ pkinit_pkcs11_code_to_text(int err);
     (*_x509_pp) = PKCS7_cert_from_signer_info(_p7,_si)
 #endif
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if (defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER < 0x10100000L) || \
+     defined(LIBRESSL_VERSION_NUMBER)
 
 /* 1.1 standardizes constructor and destructor names, renaming
  * EVP_MD_CTX_{create,destroy} and deprecating ASN1_STRING_data. */
@@ -245,6 +246,10 @@ static void compat_dh_get0_key(const DH
 
 #endif
 
+#if defined(LIBRESSL_VERSION_NUMBER) && !defined(static_ASN1_SEQUENCE_END_name)
+#define static_ASN1_SEQUENCE_END_name	ASN1_SEQUENCE_END_name
+#endif
+
 static struct pkcs11_errstrings {
     short code;
     char *text;
@@ -2924,7 +2929,9 @@ cleanup:
     return retval;
 }
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if ((defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER >= 0x10100000L) && \
+     !defined(LIBRESSL_VERSION_NUMBER)) || \
+     (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER >= 0x20900000L)
 
 /*
  * We need to decode DomainParameters from RFC 3279 section 2.3.3.  We would
