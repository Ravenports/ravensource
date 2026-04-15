--- src/lib/io/kfilesystemtype.cpp.orig	2026-03-07 20:29:56 UTC
+++ src/lib/io/kfilesystemtype.cpp
@@ -209,7 +209,7 @@ static KFileSystemType::Type determineFi
 }
 
 #elif defined(Q_OS_AIX) || defined(Q_OS_HPUX) || defined(Q_OS_QNX) || defined(Q_OS_SCO) || defined(Q_OS_UNIXWARE) || defined(Q_OS_RELIANT)                     \
-    || defined(Q_OS_NETBSD)
+    || defined(Q_OS_NETBSD) || defined(__sun)
 #include <sys/statvfs.h>
 
 KFileSystemType::Type determineFileSystemTypeImpl(const QByteArray &path)
