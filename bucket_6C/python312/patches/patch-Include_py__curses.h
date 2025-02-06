--- Include/py_curses.h.orig	2025-02-04 14:38:38 UTC
+++ Include/py_curses.h
@@ -12,6 +12,10 @@
 #endif
 #endif /* __APPLE__ */
 
+#ifdef __sun__
+#define _XOPEN_SOURCE_EXTENDED	1
+#endif /* __sun__ */
+
 /* On FreeBSD, [n]curses.h and stdlib.h/wchar.h use different guards
    against multiple definition of wchar_t and wint_t. */
 #if defined(__FreeBSD__) && defined(_XOPEN_SOURCE_EXTENDED)
