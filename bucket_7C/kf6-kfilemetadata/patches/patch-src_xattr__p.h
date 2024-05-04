--- src/xattr_p.h.orig	2024-04-05 10:56:14 UTC
+++ src/xattr_p.h
@@ -219,6 +219,8 @@ KFileMetaData::UserMetaData::Attributes
     const ssize_t size = listxattr(encodedPath, nullptr, 0);
     #elif defined(Q_OS_MAC)
     const ssize_t size = listxattr(encodedPath, nullptr, 0, 0);
+    #elif defined(__DragonFly__)
+    const ssize_t size = 0;
     #elif defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
     const ssize_t size = extattr_list_file(encodedPath, EXTATTR_NAMESPACE_USER, nullptr, 0);
     #endif
