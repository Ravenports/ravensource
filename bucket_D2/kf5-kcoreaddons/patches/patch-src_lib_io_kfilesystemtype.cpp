$NetBSD: patch-src_lib_io_kfilesystemtype.cpp,v 1.1 2022/04/28 13:59:09 jperkin Exp $

Fix #endif logic.

--- src/lib/io/kfilesystemtype.cpp.orig	2023-07-01 09:54:58 UTC
+++ src/lib/io/kfilesystemtype.cpp
@@ -210,13 +210,13 @@ KFileSystemType::Type determineFileSyste
     return kde_typeFromName(buf.f_basetype);
 #endif
 }
-#endif
 #else
 KFileSystemType::Type determineFileSystemTypeImpl(const QByteArray &path)
 {
     return KFileSystemType::Unknown;
 }
 #endif
+#endif
 
 KFileSystemType::Type KFileSystemType::fileSystemType(const QString &path)
 {
