--- libsndio/aucat.c.orig	2021-05-07 07:49:58 UTC
+++ libsndio/aucat.c
@@ -43,6 +43,26 @@
 #define DEV_RANDOM "/dev/urandom"
 #endif
 
+#ifdef __sun__
+#include <libgen.h>
+static const char *getprogname (void) {
+    static const char *progname;
+
+    if (progname == NULL) {
+        const char *e = getexecname();
+        if (e != NULL) {
+            /* Have to make a copy since getexecname can return a readonly
+               string, but basename expects to be able to modify its arg. */
+            char *n = strdup(e);
+            if (n != NULL) {
+                progname = basename(n);
+            }
+        }
+    }
+    return progname;
+}
+#endif
+
 static int
 random_bytes(unsigned char *buf, int len)
 {
@@ -472,7 +492,11 @@ parsestr(const char *str, char *rstr, un
 int
 _aucat_open(struct aucat *hdl, const char *str, unsigned int mode)
 {
+#ifdef __sun__
+	const char * __progname = getprogname();
+#else
 	extern char *__progname;
+#endif
 	int eof;
 	char host[NI_MAXHOST], opt[AMSG_OPTMAX];
 	const char *p;
