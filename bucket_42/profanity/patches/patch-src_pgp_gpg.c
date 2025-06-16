--- src/pgp/gpg.c.orig	2025-03-27 19:07:29 UTC
+++ src/pgp/gpg.c
@@ -656,7 +656,7 @@ p_gpg_decrypt(const char* const cipher)
             error = gpgme_get_key(ctx, recipient->keyid, &key, 1);
 
             if (!error && key) {
-                const char* addr = gpgme_key_get_string_attr(key, GPGME_ATTR_EMAIL, NULL, 0);
+                const char* addr = key->uids->email;
                 if (addr) {
                     g_string_append(recipients_str, addr);
                 }
