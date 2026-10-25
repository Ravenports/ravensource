--- misc/src/bsddialog/lib/formbox.c.orig	2026-09-23 15:21:28 UTC
+++ misc/src/bsddialog/lib/formbox.c
@@ -98,6 +98,8 @@ build_privateform(struct bsddialog_conf*
 	wchar_t *winit;
 	struct privateitem *item;
 
+	itemybeg = 0;
+	itemxbeg = 0;
 	/* checks */
 	CHECK_ARRAY(nitems, items);
 	for (i = 0; i < nitems; i++) {
