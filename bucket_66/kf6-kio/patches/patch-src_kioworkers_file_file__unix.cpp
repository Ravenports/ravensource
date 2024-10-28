--- src/kioworkers/file/file_unix.cpp.orig	2024-10-04 15:07:52 UTC
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
 
@@ -949,7 +953,7 @@ WorkerResult FileProtocol::listDir(const
     // qDebug() << "========= LIST " << url << "details=" << details << " =========";
     UDSEntry entry;
 
-#ifndef HAVE_DIRENT_D_TYPE
+#if !HAVE_DIRENT_D_TYPE
     QT_STATBUF st;
 #endif
     QT_DIRENT *ep;
@@ -970,7 +974,7 @@ WorkerResult FileProtocol::listDir(const
          */
         if (details == KIO::StatBasic) {
             entry.fastInsert(KIO::UDSEntry::UDS_NAME, filename);
-#ifdef HAVE_DIRENT_D_TYPE
+#if HAVE_DIRENT_D_TYPE
             entry.fastInsert(KIO::UDSEntry::UDS_FILE_TYPE, (ep->d_type == DT_DIR) ? S_IFDIR : S_IFREG);
             const bool isSymLink = (ep->d_type == DT_LNK);
 #else
