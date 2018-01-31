--- utils/v4l2-compliance/v4l2-test-controls.cpp.orig	2015-05-06 19:24:59 UTC
+++ utils/v4l2-compliance/v4l2-test-controls.cpp
@@ -32,6 +32,18 @@
 #include <vector>
 #include "v4l2-compliance.h"
 
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
 static int checkQCtrl(struct node *node, struct test_query_ext_ctrl &qctrl)
 {
 	struct v4l2_querymenu qmenu;
