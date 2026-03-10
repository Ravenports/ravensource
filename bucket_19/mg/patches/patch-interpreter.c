--- interpreter.c.orig	2024-07-09 15:39:50 UTC
+++ interpreter.c
@@ -591,7 +591,11 @@ founddef(char *defstr, int blkid, int ex
 		return(dobeep_msgs("Variable/function name clash:", vnamep));
 
 	if (!SLIST_EMPTY(&varhead)) {
+#ifdef __DragonFly__
+                SLIST_FOREACH_MUTABLE(v1, &varhead, entry, vt) {
+#else
 		SLIST_FOREACH_SAFE(v1, &varhead, entry, vt) {
+#endif
 			if (strcmp(vnamep, v1->v_name) == 0)
 				SLIST_REMOVE(&varhead, v1, varentry, entry);
 		}
