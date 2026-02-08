--- interfaces/cc/aspell.h.orig	2026-01-27 08:46:38 UTC
+++ interfaces/cc/aspell.h
@@ -245,7 +245,7 @@ void delete_aspell_can_have_error(struct
 
 /******************************** errors ********************************/
 
-
+#ifndef ASPELL_ERRORS__HPP
 extern const struct AspellErrorInfo * const aerror_other;
 extern const struct AspellErrorInfo * const aerror_operation_not_supported;
 extern const struct AspellErrorInfo * const   aerror_cant_copy;
@@ -331,7 +331,7 @@ extern const struct AspellErrorInfo * co
 extern const struct AspellErrorInfo * const   aerror_bad_magic;
 extern const struct AspellErrorInfo * const aerror_expression;
 extern const struct AspellErrorInfo * const   aerror_invalid_expression;
-
+#endif
 
 /******************************* speller *******************************/
 
