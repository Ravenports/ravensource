--- ui/qt/utils/qt_ui_utils.cpp.orig	2025-02-19 17:57:45 UTC
+++ ui/qt/utils/qt_ui_utils.cpp
@@ -44,6 +44,10 @@
 #include <QtDBus/QDBusUnixFileDescriptor>
 #endif
 
+#ifndef O_PATH
+#define O_PATH 0
+#endif
+
 /*
  * We might want to create our own "wsstring" class with convenience
  * methods for handling g_malloc()ed strings, GStrings, and a shortcut
