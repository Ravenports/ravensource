--- lib/softoken/pkcs11c.c.orig	2017-09-20 06:47:27 UTC
+++ lib/softoken/pkcs11c.c
@@ -5728,9 +5728,6 @@ sftk_unwrapPrivateKey(SFTKObject *key, S
             break;
         case NSSLOWKEYDSAKey:
             keyType = CKK_DSA;
-            crv = (sftk_hasAttribute(key, CKA_NETSCAPE_DB)) ? CKR_OK : CKR_KEY_TYPE_INCONSISTENT;
-            if (crv != CKR_OK)
-                break;
             crv = sftk_AddAttributeType(key, CKA_KEY_TYPE, &keyType,
                                         sizeof(keyType));
             if (crv != CKR_OK)
@@ -5770,9 +5767,6 @@ sftk_unwrapPrivateKey(SFTKObject *key, S
         /* what about fortezza??? */
         case NSSLOWKEYECKey:
             keyType = CKK_EC;
-            crv = (sftk_hasAttribute(key, CKA_NETSCAPE_DB)) ? CKR_OK : CKR_KEY_TYPE_INCONSISTENT;
-            if (crv != CKR_OK)
-                break;
             crv = sftk_AddAttributeType(key, CKA_KEY_TYPE, &keyType,
                                         sizeof(keyType));
             if (crv != CKR_OK)
