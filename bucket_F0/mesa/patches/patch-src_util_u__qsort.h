--- src/util/u_qsort.h.orig	2026-02-19 18:55:18 UTC
+++ src/util/u_qsort.h
@@ -56,7 +56,7 @@ util_qsort_r(void *base, size_t nmemb, s
              int (*compar)(const void *, const void *, void *),
              void *arg)
 {
-#if defined(HAVE_GNU_QSORT_R)
+#if defined(HAVE_GNU_QSORT_R) || defined(__sun__)
    /* GNU extension added in glibc 2.8 */
    qsort_r(base, nmemb, size, compar, arg);
 #elif defined(HAVE_BSD_QSORT_R)
