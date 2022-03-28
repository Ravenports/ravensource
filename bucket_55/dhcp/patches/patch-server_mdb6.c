--- server/mdb6.c.orig	2022-03-08 09:26:03 UTC
+++ server/mdb6.c
@@ -1129,7 +1129,7 @@ create_lease6(struct ipv6_pool *pool, st
 		}
 		new_ds.data = new_ds.buffer->data;
 		memcpy(new_ds.buffer->data, ds.data, ds.len);
-		memcpy(new_ds.buffer->data + ds.len, &tmp, sizeof(tmp));
+		memcpy(&new_ds.buffer->data[0] + ds.len, &tmp, sizeof(tmp));
 		data_string_forget(&ds, MDL);
 		data_string_copy(&ds, &new_ds, MDL);
 		data_string_forget(&new_ds, MDL);
