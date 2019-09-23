--- interfaces/cc/aspell.h.orig	2019-06-24 20:03:55 UTC
+++ interfaces/cc/aspell.h
@@ -243,7 +243,7 @@ void delete_aspell_can_have_error(struct
 
 /******************************** errors ********************************/
 
-
+#ifndef ASPELL_ERRORS__HPP
 extern const struct AspellErrorInfo * const aerror_other;
 extern const struct AspellErrorInfo * const aerror_operation_not_supported;
 extern const struct AspellErrorInfo * const   aerror_cant_copy;
@@ -329,7 +329,7 @@ extern const struct AspellErrorInfo * co
 extern const struct AspellErrorInfo * const   aerror_bad_magic;
 extern const struct AspellErrorInfo * const aerror_expression;
 extern const struct AspellErrorInfo * const   aerror_invalid_expression;
-
+#endif
 
 /******************************* speller *******************************/
 
