--- server/mdb6.c.orig	2021-05-14 10:51:30 UTC
+++ server/mdb6.c
@@ -1945,7 +1945,7 @@ create_prefix6(struct ipv6_pool *pool, s
 		}
 		new_ds.data = new_ds.buffer->data;
 		memcpy(new_ds.buffer->data, ds.data, ds.len);
-		memcpy(new_ds.buffer->data + ds.len, &tmp, sizeof(tmp));
+		memcpy(&new_ds.buffer->data[0] + ds.len, &tmp, sizeof(tmp));
 		data_string_forget(&ds, MDL);
 		data_string_copy(&ds, &new_ds, MDL);
 		data_string_forget(&new_ds, MDL);
