--- texk/xdvik/encodings.c.orig	2014-06-23 09:36:07 UTC
+++ texk/xdvik/encodings.c
@@ -3056,7 +3056,13 @@ cjk2unicode(unsigned char *cjk)
 	register_exit_handler(close_iconv, NULL);
 	
     }
-    if (iconv(m_iconv_gb_ucs4, (iconv_char_pptrT)&from_ptr, &from, &to_ptr, &to) == (size_t)(-1)) {
+    if (iconv(m_iconv_gb_ucs4,
+#if defined(__sun)
+	(const char **)&from_ptr,
+#else
+	(iconv_char_pptrT)&from_ptr,
+#endif
+	&from, &to_ptr, &to) == (size_t)(-1)) {
 	XDVI_ERROR((stderr, "cjk2unicode: can't convert GBK to unicode: %s", strerror(errno)));
 	return 0;
     }
