--- src/html/html_document.c.orig	2023-12-27 15:52:07 UTC
+++ src/html/html_document.c
@@ -134,13 +134,13 @@ dom_exception _dom_html_document_initial
 	doc->cookie = NULL;
 	doc->body = NULL;
 
-	doc->memoised = calloc(sizeof(dom_string *), hds_COUNT);
+	doc->memoised = calloc(hds_COUNT, sizeof(dom_string *));
 	if (doc->memoised == NULL) {
 		error = DOM_NO_MEM_ERR;
 		goto out;
 	}
-	doc->elements = calloc(sizeof(dom_string *),
-			DOM_HTML_ELEMENT_TYPE__COUNT);
+	doc->elements = calloc(DOM_HTML_ELEMENT_TYPE__COUNT,
+			sizeof(dom_string *));
 	if (doc->elements == NULL) {
 		error = DOM_NO_MEM_ERR;
 		goto out;
