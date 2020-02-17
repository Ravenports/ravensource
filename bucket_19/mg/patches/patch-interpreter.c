--- interpreter.c.orig	2020-02-15 14:33:45 UTC
+++ interpreter.c
@@ -304,7 +304,11 @@ foundlist(char *defstr)
 	 * in a linked list. But first remove variable, if existing already.
 	 */
 	if (!SLIST_EMPTY(&varhead)) {
+#ifdef __DragonFly__
+		SLIST_FOREACH_MUTABLE(v1, &varhead, entry, vt) {
+#else
 		SLIST_FOREACH_SAFE(v1, &varhead, entry, vt) {
+#endif
 			if (strcmp(vnamep, v1->name) == 0)
 				SLIST_REMOVE(&varhead, v1, varentry, entry);
 		}
