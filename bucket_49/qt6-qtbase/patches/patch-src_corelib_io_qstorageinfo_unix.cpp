$NetBSD: patch-src_corelib_io_qstorageinfo_unix.cpp,v 1.2 2024/04/27 11:49:40 adam Exp $

Fix build on SunOS.

--- src/corelib/io/qstorageinfo_unix.cpp.orig	2024-11-14 11:02:40 UTC
+++ src/corelib/io/qstorageinfo_unix.cpp
@@ -50,7 +50,7 @@
 #  if !defined(_STATFS_F_FLAGS) && !defined(Q_OS_NETBSD)
 #    define _STATFS_F_FLAGS 1
 #  endif
-#elif defined(Q_OS_HAIKU)
+#elif defined(Q_OS_HAIKU) || defined(Q_OS_SOLARIS)
 #  define QT_STATFSBUF struct statvfs
 #  define QT_STATFS    ::statvfs
 #else
