$NetBSD: patch-include_violite.h,v 1.1 2022/11/27 22:12:25 nia Exp $

pthread_t on NetBSD is a pointer to a struct. To account for the
C++ type system we need to use an actual NULL pointer rather than
an incompatible integer type.

--- include/violite.h.orig	2025-03-31 07:51:10 UTC
+++ include/violite.h
@@ -346,7 +346,11 @@ struct Vio {
     It is initialized to 0 here, meaning don't attempt to send a signal, to
     keep non-server code unaffected.
   */
+#ifdef __NetBSD__
+  std::optional<my_thread_t> thread_id = nullptr;
+#else
   std::optional<my_thread_t> thread_id = 0;
+#endif
   sigset_t signal_mask;  // Signal mask
   /*
     Flag to indicate whether we are in poll or shutdown.
