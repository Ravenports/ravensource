--- src/dbi_result.c.orig	2013-01-08 23:54:30 UTC
+++ src/dbi_result.c
@@ -1470,10 +1470,10 @@ char *dbi_result_get_as_string_copy_idx(
     switch (RESULT->field_attribs[fieldidx] & DBI_INTEGER_SIZEMASK) {
     case DBI_INTEGER_SIZE1:
       if (RESULT->field_attribs[fieldidx] & DBI_INTEGER_UNSIGNED) {
-	snprintf(newstring, 32, "%hu", RESULT->rows[RESULT->currowidx]->field_values[fieldidx].d_char);
+	snprintf(newstring, 32, "%hhu", RESULT->rows[RESULT->currowidx]->field_values[fieldidx].d_char);
       }
       else {
-	snprintf(newstring, 32, "%hd", RESULT->rows[RESULT->currowidx]->field_values[fieldidx].d_char);
+	snprintf(newstring, 32, "%hhd", RESULT->rows[RESULT->currowidx]->field_values[fieldidx].d_char);
       }
       break;
     case DBI_INTEGER_SIZE2:
