--- yaml.c.orig	2025-11-12 02:22:12 UTC
+++ yaml.c
@@ -528,7 +528,7 @@ PHP_FUNCTION(yaml_parse_url)
 
 	if (zndocs != NULL) {
 		/* copy document count to var user sent in */
-		zval_dtor(zndocs);
+		zval_ptr_dtor(zndocs);
 		ZVAL_LONG(zndocs, ndocs);
 	}
 
