--- spa/include/spa/utils/json-pod.h.orig	2024-10-23 07:44:10 UTC
+++ spa/include/spa/utils/json-pod.h
@@ -115,7 +115,7 @@ static inline int spa_json_to_pod_part(s
 		spa_pod_builder_none(b);
 	}
 	else {
-		char *val = (char*)alloca(len+1);
+		char *val = (char*)__builtin_alloca(len+1);
 		spa_json_parse_stringn(value, len, val, len+1);
 		switch (info ? info->parent : (uint32_t)SPA_TYPE_Struct) {
 		case SPA_TYPE_Id:
