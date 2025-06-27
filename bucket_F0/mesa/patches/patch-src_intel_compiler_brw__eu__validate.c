--- src/intel/compiler/brw_eu_validate.c.orig	2025-06-18 17:45:40 UTC
+++ src/intel/compiler/brw_eu_validate.c
@@ -97,6 +97,39 @@ typedef struct brw_hw_decoded_inst {
    } src[3];
 } brw_hw_decoded_inst;
 
+#ifdef __sun__
+#include <string.h>
+
+static void *
+memmem(const void *l, size_t l_len, const void *s, size_t s_len)
+{
+	char *cur, *last;
+	const char *cl = (const char *)l;
+	const char *cs = (const char *)s;
+
+	/* we need something to compare */
+	if (l_len == 0 || s_len == 0)
+		return NULL;
+
+	/* "s" must be smaller or equal to "l" */
+	if (l_len < s_len)
+		return NULL;
+
+	/* special case where s_len == 1 */
+	if (s_len == 1)
+		return memchr(l, (int)*cs, l_len);
+
+	/* the last position where its possible to find "s" in "l" */
+	last = (char *)cl + l_len - s_len;
+
+	for (cur = (char *)cl; cur <= last; cur++)
+		if (cur[0] == cs[0] && memcmp(cur, cs, s_len) == 0)
+			return cur;
+
+	return NULL;
+}
+#endif
+
 /* We're going to do lots of string concatenation, so this should help. */
 struct string {
    char *str;
