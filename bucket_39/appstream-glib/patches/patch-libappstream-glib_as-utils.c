--- libappstream-glib/as-utils.c.orig	2018-02-09 11:34:12 UTC
+++ libappstream-glib/as-utils.c
@@ -1470,18 +1470,21 @@ as_utils_guid_from_data (const gchar *na
 	gchar guid_new[37]; /* 36 plus NUL */
 	gsize digestlen = 20;
 	guint8 hash[20];
-	gint rc;
-	uuid_t uu_namespace;
-	uuid_t uu_new;
+	uuid_rc_t rc;
+	uuid_t *namespace_uuid;
+	uuid_t *new_uuid;
 	g_autoptr(GChecksum) csum = NULL;
+	guchar ns_binary[UUID_LEN_BIN] = { 0 };
+	size_t ns_binlen = UUID_LEN_BIN;
 
 	g_return_val_if_fail (namespace_id != NULL, FALSE);
 	g_return_val_if_fail (data != NULL, FALSE);
 	g_return_val_if_fail (data_len != 0, FALSE);
 
-	/* convert the namespace to binary */
-	rc = uuid_parse (namespace_id, uu_namespace);
-	if (rc != 0) {
+	/* convert the namespace to abstract uuid type */
+	uuid_create (&namespace_uuid);
+	rc = uuid_import (namespace_uuid, UUID_FMT_STR, namespace_id, UUID_LEN_STR);
+	if (rc != UUID_RC_OK) {
 		g_set_error (error,
 			     AS_UTILS_ERROR,
 			     AS_UTILS_ERROR_FAILED,
@@ -1489,22 +1492,45 @@ as_utils_guid_from_data (const gchar *na
 			     namespace_id);
 		return FALSE;
 	}
+	/* convert imported uuid to binary */
+	rc = uuid_export(namespace_uuid, UUID_FMT_BIN, &ns_binary, &ns_binlen);
+	if (rc != UUID_RC_OK) {
+		g_set_error (error,
+			     AS_UTILS_ERROR,
+			     AS_UTILS_ERROR_FAILED,
+			     "namespace '%s' binary conversion failed",
+			     namespace_id);
+		return FALSE;
+	}
+	
 
 	/* hash the namespace and then the string */
 	csum = g_checksum_new (G_CHECKSUM_SHA1);
-	g_checksum_update (csum, (guchar *) uu_namespace, 16);
+	g_checksum_update (csum, ns_binary, UUID_LEN_BIN);
 	g_checksum_update (csum, (guchar *) data, (gssize) data_len);
 	g_checksum_get_digest (csum, hash, &digestlen);
 
-	/* copy most parts of the hash 1:1 */
-	memcpy (uu_new, hash, 16);
+	/* namespace_uuid no longer needed */
+	uuid_destroy(namespace_uuid);
 
 	/* set specific bits according to Section 4.1.3 */
-	uu_new[6] = (guint8) ((uu_new[6] & 0x0f) | (5 << 4));
-	uu_new[8] = (guint8) ((uu_new[8] & 0x3f) | 0x80);
+	hash[6] = (guint8) ((hash[6] & 0x0f) | (5 << 4));
+	hash[8] = (guint8) ((hash[8] & 0x3f) | 0x80);
+
+	/* create a new from first 16 bytes of hash */
+	uuid_create (&new_uuid);
+	rc = uuid_import (new_uuid, UUID_FMT_BIN, hash, UUID_LEN_BIN);
+	if (rc != UUID_RC_OK) {
+		g_set_error (error,
+			     AS_UTILS_ERROR,
+			     AS_UTILS_ERROR_FAILED,
+			     "imported arranged hash failed");
+		return FALSE;
+	}
 
 	/* return as a string */
-	uuid_unparse (uu_new, guid_new);
+	uuid_export(new_uuid, UUID_FMT_STR, &guid_new, NULL);
+	uuid_destroy(new_uuid);
 	return g_strdup (guid_new);
 }
 
@@ -1521,12 +1547,14 @@ as_utils_guid_from_data (const gchar *na
 gboolean
 as_utils_guid_is_valid (const gchar *guid)
 {
-	gint rc;
-	uuid_t uu;
+	uuid_rc_t rc;
+	uuid_t *tmp_uuid;
 	if (guid == NULL)
 		return FALSE;
-	rc = uuid_parse (guid, uu);
-	return rc == 0;
+	uuid_create(&tmp_uuid);
+	rc = uuid_import (tmp_uuid, UUID_FMT_STR, guid, UUID_LEN_STR);
+	uuid_destroy(tmp_uuid);
+	return (rc == UUID_RC_OK);
 }
 
 /**
