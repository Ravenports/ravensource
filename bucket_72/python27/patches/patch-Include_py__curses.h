--- Include/py_curses.h.orig	2017-12-19 04:53:56 UTC
+++ Include/py_curses.h
@@ -12,6 +12,10 @@
 #endif
 #endif /* __APPLE__ */
 
+#ifdef __sun__
+#define _XOPEN_SOURCE_EXTENDED	1
+#endif /* __sun__ */
+
 #ifdef __FreeBSD__
 /*
 ** On FreeBSD, [n]curses.h and stdlib.h/wchar.h use different guards
