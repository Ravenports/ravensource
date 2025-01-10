--- src/xattr_p.h.orig	2025-01-03 15:26:16 UTC
+++ src/xattr_p.h
@@ -240,6 +240,8 @@ KFileMetaData::UserMetaData::Attributes
     const ssize_t size = listxattr(encodedPath, nullptr, 0);
     #elif defined(Q_OS_MAC)
     const ssize_t size = listxattr(encodedPath, nullptr, 0, 0);
+    #elif defined(__DragonFly__)
+    const ssize_t size = 0;
     #elif defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
     const ssize_t size = extattr_list_file(encodedPath, EXTATTR_NAMESPACE_USER, nullptr, 0);
     #endif
