--- src/kioworkers/file/file_unix.cpp.orig	2024-04-05 10:57:02 UTC
+++ src/kioworkers/file/file_unix.cpp
@@ -530,6 +530,9 @@ WorkerResult FileProtocol::tryChangeFile
 #if HAVE_SYS_XATTR_H || HAVE_SYS_EXTATTR_H
 bool FileProtocol::copyXattrs(const int src_fd, const int dest_fd)
 {
+# if defined(__DragonFly__)  // Header present, extattr_list_fd defined but not implemented
+    return true;
+# else
     // Get the list of keys
     ssize_t listlen = 0;
     QByteArray keylist;
@@ -645,6 +648,7 @@ bool FileProtocol::copyXattrs(const int
         next_key();
     }
     return true;
+# endif // __DragonFly__
 }
 #endif // HAVE_SYS_XATTR_H || HAVE_SYS_EXTATTR_H
 
