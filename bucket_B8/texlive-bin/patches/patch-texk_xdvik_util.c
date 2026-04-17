--- texk/xdvik/util.c.orig	2022-02-18 23:04:03 UTC
+++ texk/xdvik/util.c
@@ -1858,7 +1858,13 @@ iconv_convert_string(const char *from_en
     }
 
     TRACE_FIND((stderr, "iconv_convert_string: from `%s', to `%s'", from_enc, to_enc));
-    if (iconv(conv_desc, (iconv_char_pptrT)&in_ptr, &input_len, (char **)&out_ptr, &conv_len) == (size_t)(-1)) {
+    if (iconv(conv_desc,
+#if defined(__sun)
+	(const char **)&in_ptr,
+#else
+	(iconv_char_pptrT)&in_ptr,
+#endif
+	&input_len, (char **)&out_ptr, &conv_len) == (size_t)(-1)) {
 	popup_message(XtNameToWidget(globals.widgets.top_level, "*find_popup"),
 		      MSG_ERR,
 		      NULL,
