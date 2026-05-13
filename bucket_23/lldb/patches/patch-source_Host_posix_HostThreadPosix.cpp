--- source/Host/posix/HostThreadPosix.cpp.orig	2026-05-04 22:50:13 UTC
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
