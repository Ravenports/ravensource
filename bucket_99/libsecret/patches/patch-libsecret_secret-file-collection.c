Avoid conflict with encrypt definition on /usr/include/unistd on DF

--- libsecret/secret-file-collection.c.orig	2019-10-14 15:15:45 UTC
+++ libsecret/secret-file-collection.c
@@ -164,7 +164,7 @@ decrypt (SecretFileCollection *self,
 }
 
 static gboolean
-encrypt (SecretFileCollection *self,
+secret_encrypt (SecretFileCollection *self,
 	 guint8 *data,
 	 gsize n_data)
 {
@@ -584,7 +584,7 @@ secret_file_collection_replace (SecretFi
 	g_variant_store (serialized_item, data);
 	g_variant_unref (serialized_item);
 	memset (data + n_data, n_padded - n_data, n_padded - n_data);
-	if (!encrypt (self, data, n_padded)) {
+	if (!secret_encrypt (self, data, n_padded)) {
 		egg_secure_free (data);
 		g_set_error (error,
 			     SECRET_ERROR,
