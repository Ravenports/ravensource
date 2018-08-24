--- dired.c.orig	2018-07-13 09:16:01 UTC
+++ dired.c
@@ -956,7 +956,11 @@ redelete(struct buffer *bp)
 			continue;
 		}
 		plen = strlen(p);
+#ifdef __DragonFly__
+		SLIST_FOREACH_MUTABLE(d1, &delhead, entry, dt) {
+#else
 		SLIST_FOREACH_SAFE(d1, &delhead, entry, dt) {
+#endif
 			fnlen = strlen(d1->fn);
 			if ((plen == fnlen) && 
 			    (strncmp(p, d1->fn, plen) == 0)) {
