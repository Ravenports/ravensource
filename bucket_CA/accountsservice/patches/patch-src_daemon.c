--- src/daemon.c.orig	2023-08-12 19:01:30 UTC
+++ src/daemon.c
@@ -245,7 +245,12 @@ static GHashTable* build_shadow_users_ha
 
                 ShadowEntryBuffers *shadow_entry_buffers = g_malloc0 (sizeof(*shadow_entry_buffers));
 
+#if defined(__sun)
+                shadow_entry = fgetspent_r (fp, &shadow_entry_buffers->spbuf, shadow_entry_buffers->buf, sizeof(shadow_entry_buffers->buf));
+		ret = (shadow_entry != NULL) ? 0 : -1;
+#else
                 ret = fgetspent_r (fp, &shadow_entry_buffers->spbuf, shadow_entry_buffers->buf, sizeof(shadow_entry_buffers->buf), &shadow_entry);
+#endif
                 if (ret == 0) {
                         g_hash_table_insert (shadow_users, g_strdup (shadow_entry->sp_namp), shadow_entry_buffers);
                         g_hash_table_add (local_users, g_strdup (shadow_entry->sp_namp));
