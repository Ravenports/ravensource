--- src/misc_tools.c.orig	2026-02-12 15:23:42 UTC
+++ src/misc_tools.c
@@ -26,6 +26,24 @@
 #include "toxic.h"
 #include "windows.h"
 
+#if defined(__NetBSD__) && (__NetBSD_Version__ < 1100000000)
+/* Fallback for older NetBSD versions lacking qsort_r */
+static __thread void *qsort_r_arg;
+static __thread int (*qsort_r_compar)(const void *, const void *, void *);
+
+static int qsort_r_wrapper(const void *a, const void *b) {
+    return qsort_r_compar(a, b, qsort_r_arg);
+}
+
+void qsort_r(void *base, size_t nmemb, size_t size,
+             int (*compar)(const void *, const void *, void *),
+             void *arg) {
+    qsort_r_arg = arg;
+    qsort_r_compar = compar;
+    qsort(base, nmemb, size, qsort_r_wrapper);
+}
+#endif
+
 void clear_screen(void)
 {
     printf("\033[2J\033[1;1H");
