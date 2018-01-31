--- utils/v4l2-compliance/v4l2-compliance.cpp.orig	2015-05-06 19:24:59 UTC
+++ utils/v4l2-compliance/v4l2-compliance.cpp
@@ -236,6 +236,18 @@ const char *ok(int res)
 	return buf;
 }
 
+#ifdef __sun__
+static size_t
+strnlen(const char *s, size_t maxlen)
+{
+	size_t len;
+	for (len = 0; len < maxlen; len++, s++) {
+		if (!*s) break;
+	}
+	return (len);
+}
+#endif
+
 int check_string(const char *s, size_t len)
 {
 	size_t sz = strnlen(s, len);
