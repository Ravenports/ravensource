--- lib/softoken/pkcs11c.c.orig	2025-06-19 13:14:58 UTC
+++ lib/softoken/pkcs11c.c
@@ -6642,9 +6642,6 @@ sftk_unwrapPrivateKey(SFTKObject *key, S
             break;
         case NSSLOWKEYDSAKey:
             keyType = CKK_DSA;
-            crv = (sftk_hasAttribute(key, CKA_NSS_DB)) ? CKR_OK : CKR_KEY_TYPE_INCONSISTENT;
-            if (crv != CKR_OK)
-                break;
             crv = sftk_AddAttributeType(key, CKA_KEY_TYPE, &keyType,
                                         sizeof(keyType));
             if (crv != CKR_OK)
@@ -6684,9 +6681,6 @@ sftk_unwrapPrivateKey(SFTKObject *key, S
         /* what about fortezza??? */
         case NSSLOWKEYECKey:
             keyType = CKK_EC;
-            crv = (sftk_hasAttribute(key, CKA_NSS_DB)) ? CKR_OK : CKR_KEY_TYPE_INCONSISTENT;
-            if (crv != CKR_OK)
-                break;
             crv = sftk_AddAttributeType(key, CKA_KEY_TYPE, &keyType,
                                         sizeof(keyType));
             if (crv != CKR_OK)
