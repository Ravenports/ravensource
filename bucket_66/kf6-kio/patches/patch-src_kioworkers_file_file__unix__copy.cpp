--- src/kioworkers/file/file_unix_copy.cpp.orig	2026-10-02 13:20:17 UTC
+++ src/kioworkers/file/file_unix_copy.cpp
@@ -107,7 +107,9 @@ bool FileProtocol::copyXattrs(const int
 #elif defined(Q_OS_MAC)
         listlen = flistxattr(src_fd, keylist.data(), listlen, 0);
 #elif HAVE_SYS_EXTATTR_H
+#  if !defined(__DragonFly__) // Header present, extattr_list_fd defined but not implemented 
         listlen = extattr_list_fd(src_fd, EXTATTR_NAMESPACE_USER, listlen == 0 ? nullptr : keylist.data(), listlen);
+#  endif
 #endif
         if (listlen > 0 && keylist.size() == 0) {
             continue;
