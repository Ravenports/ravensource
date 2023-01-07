$NetBSD: patch-boost_process_detail_posix_handles.hpp,v 1.2 2020/09/10 07:54:52 tnn Exp $

dirfd(3) on NetBSD is implemented as a macro and cannot use namespace prefix.

--- boost/process/detail/posix/handles.hpp.orig	2022-12-08 01:02:46 UTC
+++ boost/process/detail/posix/handles.hpp
@@ -33,7 +33,11 @@ inline std::vector<native_handle_type> g
     else
         ec.clear();
 
+#ifdef dirfd
+    auto my_fd = dirfd(dir.get());
+#else
     auto my_fd = ::dirfd(dir.get());
+#endif
 
     struct ::dirent * ent_p;
 
@@ -117,7 +121,11 @@ struct limit_handles_ : handler_base_ext
             return;
         }
 
+#ifdef dirfd
+        auto my_fd = dirfd(dir);
+#else
         auto my_fd = ::dirfd(dir);
+#endif
         struct ::dirent * ent_p;
 
         while ((ent_p = readdir(dir)) != nullptr)
