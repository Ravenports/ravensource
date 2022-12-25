--- src/libxls/locale.c.orig	2022-03-28 17:24:54 UTC
+++ src/libxls/locale.c
@@ -78,7 +78,7 @@ size_t xls_wcstombs_l(char *restrict s,
     return wcstombs(s, pwcs, n);
 #elif defined(_WIN32) || defined(WIN32) || defined(_WIN64) || defined(WIN64) || defined(WINDOWS)
     return _wcstombs_l(s, pwcs, n, loc);
-#elif defined(HAVE_WCSTOMBS_L)
+#elif defined(HAVE_WCSTOMBS_L) || defined(__NetBSD__)
     return wcstombs_l(s, pwcs, n, loc);
 #else
     locale_t oldlocale = uselocale(loc);
