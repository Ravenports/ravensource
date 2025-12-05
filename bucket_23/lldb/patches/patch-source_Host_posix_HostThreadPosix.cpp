--- source/Host/posix/HostThreadPosix.cpp.orig	2025-12-01 12:58:50 UTC
+++ source/Host/posix/HostThreadPosix.cpp
@@ -40,7 +40,7 @@ Status HostThreadPosix::Join(lldb::threa
 Status HostThreadPosix::Cancel() {
   Status error;
   if (IsJoinable()) {
-#ifndef __FreeBSD__
+#if !defined(__FreeBSD__) && !defined(__DragonFly__)
     llvm_unreachable("someone is calling HostThread::Cancel()");
 #else
     int err = ::pthread_cancel(m_thread);
