--- spa/include/spa/utils/json-pod.h.orig	2025-09-11 08:12:34 UTC
+++ spa/include/spa/utils/json-pod.h
@@ -121,7 +121,7 @@ SPA_API_JSON_POD int spa_json_to_pod_par
 		spa_pod_builder_none(b);
 	}
 	else {
-		char *val = (char*)alloca(len+1);
+		char *val = (char*)__builtin_alloca(len+1);
 		spa_json_parse_stringn(value, len, val, len+1);
 		switch (info ? info->parent : (uint32_t)SPA_TYPE_Struct) {
 		case SPA_TYPE_Id:
