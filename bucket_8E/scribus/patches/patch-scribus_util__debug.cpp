--- scribus/util_debug.cpp.orig	2024-06-15 14:22:34 UTC
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
