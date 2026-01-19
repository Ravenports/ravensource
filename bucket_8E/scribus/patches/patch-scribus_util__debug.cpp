--- scribus/util_debug.cpp.orig	2026-01-19 14:51:40 UTC
+++ scribus/util_debug.cpp
@@ -53,7 +53,7 @@ void tDebug(const QString& message)
  */
 void printBacktrace ( int nFrames )
 {
-#if !defined(_WIN32) && !defined(Q_OS_MACOS) && !defined(Q_OS_OPENBSD) && !defined(Q_OS_FREEBSD)
+#if !defined(_WIN32) && !defined(Q_OS_MACOS) && !defined(Q_OS_OPENBSD) && !defined(Q_OS_FREEBSD) && !defined(Q_OS_NETBSD)
 	void ** trace = new void*[nFrames + 1];
 	char **messages = ( char ** ) nullptr;
 	int i, trace_size = 0;
