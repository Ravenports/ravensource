--- common/conv.h.orig	2007-11-18 16:41:42 UTC
+++ common/conv.h
@@ -21,3 +21,6 @@ struct _conv {
 	char2wchar_t	input2int;
 	wchar2char_t	int2disp;
 };
+
+int conv_enc (SCR *, int, char *);
+void conv_init (SCR *, SCR *);
