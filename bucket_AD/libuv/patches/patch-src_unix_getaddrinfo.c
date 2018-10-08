--- src/unix/getaddrinfo.c.orig	2018-10-08 16:52:30 UTC
+++ src/unix/getaddrinfo.c
@@ -37,6 +37,17 @@
 /* EAI_* constants. */
 #include <netdb.h>
 
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
 
 int uv__getaddrinfo_translate_error(int sys_err) {
   switch (sys_err) {
