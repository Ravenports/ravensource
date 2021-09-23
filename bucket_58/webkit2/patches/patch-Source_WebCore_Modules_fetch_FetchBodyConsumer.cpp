--- Source/WebCore/Modules/fetch/FetchBodyConsumer.cpp.orig	2021-09-01 09:16:50 UTC
+++ Source/WebCore/Modules/fetch/FetchBodyConsumer.cpp
@@ -38,6 +38,32 @@
 #include <wtf/StringExtras.h>
 #include <wtf/URLParser.h>
 
+#ifdef __sun
+static void *memmem(
+		const void *big, size_t big_len,
+		const void *little, size_t little_len)
+{
+	const char *bp = (const char *)big;
+	const char *lp = (const char *)little;
+	size_t l;
+
+	if (big_len < little_len || little_len == 0 || big_len == 0)
+		return NULL;
+
+	while (big_len > 0) {
+		for (l = 0; l < little_len; l++) {
+			if (bp[l] != lp[l])
+				break;
+		}
+		if (l == little_len)
+			return (void *)bp;
+		bp++;
+	}
+
+	return NULL;
+}
+#endif
+
 namespace WebCore {
 
 static inline Ref<Blob> blobFromData(ScriptExecutionContext* context, Vector<uint8_t>&& data, const String& contentType)
