--- Include/py_curses.h.orig	2020-04-19 21:13:39 UTC
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
