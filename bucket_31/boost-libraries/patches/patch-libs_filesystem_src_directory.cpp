Fix "error: expected id-expression before '(' token" (dirfd() is defined as a macro on NetBSD).

--- libs/filesystem/src/directory.cpp.orig	2024-08-07 22:07:35 UTC
+++ libs/filesystem/src/directory.cpp
@@ -270,7 +270,11 @@ inline system::error_code dir_itr_close(
 // Obtains a file descriptor from the directory iterator
 inline int dir_itr_fd(dir_itr_imp const& imp, system::error_code& ec)
 {
+#if defined __NetBSD__
+    int fd = dirfd(static_cast< DIR* >(imp.handle));
+#else
     int fd = ::dirfd(static_cast< DIR* >(imp.handle));
+#endif
     if (BOOST_UNLIKELY(fd < 0))
     {
         int err = errno;
