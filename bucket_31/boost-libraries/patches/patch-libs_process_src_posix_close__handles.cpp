--- libs/process/src/posix/close_handles.cpp.orig	2024-12-05 00:53:35 UTC
+++ libs/process/src/posix/close_handles.cpp
@@ -185,7 +185,11 @@ void close_all(const std::vector<int> &
         return ;
     }
 
+#if defined(__NetBSD__)
+    auto dir_fd = dirfd(dir.get());
+#else
     auto dir_fd = ::dirfd(dir.get());
+#endif
     if (dir_fd == -1)
     {
         ec = BOOST_PROCESS_V2_NAMESPACE::detail::get_last_error();
