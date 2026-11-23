--- parse.c.orig	2025-11-12 02:22:12 UTC
+++ parse.c
@@ -924,7 +924,7 @@ eval_timestamp(zval **zpp, const char *t
 		}
 
 	} else {
-		zval_dtor(*zpp);
+		zval_ptr_dtor_nogc(*zpp);
 		ZVAL_STRINGL(*zpp, ts, ts_len);
 		return SUCCESS;
 	}
