--- src/ucl_util.c.orig	2026-02-17 10:43:22 UTC
+++ src/ucl_util.c
@@ -2509,7 +2509,7 @@ ucl_object_pop_keyl(ucl_object_t *top, c
 	const ucl_object_t *found;
 
 	if (top == NULL || key == NULL) {
-		return false;
+		return NULL;
 	}
 	found = ucl_object_lookup_len(top, key, keylen);
 
