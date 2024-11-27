--- src/friend.c.orig	2024-11-27 11:53:58 UTC
+++ src/friend.c
@@ -491,7 +491,7 @@ void friend_add(char *name, uint16_t len
         friend_addid(id, msg, msg_length);
     } else if (length_cleaned == TOX_PUBLIC_KEY_SIZE * 2) {
         string_to_id(id, (char*)name_cleaned);
-        uint8_t *data = calloc(sizeof(uint8_t), TOX_PUBLIC_KEY_SIZE);
+        uint8_t *data = calloc(TOX_PUBLIC_KEY_SIZE, sizeof(uint8_t));
         if (!data) {
             LOG_ERR("Calloc", "Memory allocation failed!");
             return;
