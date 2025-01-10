--- src/kioworkers/file/file_unix.cpp.orig	2025-01-08 18:54:33 UTC
+++ src/kioworkers/file/file_unix.cpp
@@ -413,6 +413,9 @@ WorkerResult FileProtocol::tryChangeFile
 #if HAVE_SYS_XATTR_H || HAVE_SYS_EXTATTR_H
 bool FileProtocol::copyXattrs(const int src_fd, const int dest_fd)
 {
+# if defined(__DragonFly__)  // Header present, extattr_list_fd defined but not implemented
+    return true;
+# else
     // Get the list of keys
     ssize_t listlen = 0;
     QByteArray keylist;
@@ -528,6 +531,7 @@ bool FileProtocol::copyXattrs(const int
         next_key();
     }
     return true;
+# endif // __DragonFly__
 }
 #endif // HAVE_SYS_XATTR_H || HAVE_SYS_EXTATTR_H
 
