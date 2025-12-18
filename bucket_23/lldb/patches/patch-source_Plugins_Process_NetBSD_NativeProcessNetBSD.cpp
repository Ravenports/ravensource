--- source/Plugins/Process/NetBSD/NativeProcessNetBSD.cpp.orig	2025-12-01 12:58:50 UTC
+++ source/Plugins/Process/NetBSD/NativeProcessNetBSD.cpp
@@ -302,9 +302,9 @@ void NativeProcessNetBSD::MonitorSIGTRAP
       LLDB_LOG(log, "monitoring new thread, pid = {0}, LWP = {1}", pid,
                pst.pe_lwp);
       NativeThreadNetBSD &t = AddThread(pst.pe_lwp);
-      error = t.CopyWatchpointsFrom(
+      llvm:Error myerror = t.CopyWatchpointsFrom(
           static_cast<NativeThreadNetBSD &>(*GetCurrentThread()));
-      if (error.Fail()) {
+      if (myerror) {
         LLDB_LOG(log, "failed to copy watchpoints to new thread {0}: {1}",
                  pst.pe_lwp, error);
         SetState(StateType::eStateInvalid);
@@ -489,8 +489,10 @@ Status NativeProcessNetBSD::Resume(const
 
   Expected<ptrace_siginfo_t> siginfo =
       ComputeSignalInfo(m_threads, resume_actions);
-  if (!siginfo)
-    return Status(siginfo.takeError());
+  if (!siginfo) {
+    ret = Status::FromErrorString("Failed to compute signal information");
+    return ret;
+  }
 
   for (const auto &abs_thread : m_threads) {
     assert(abs_thread && "thread list should not contain NULL threads");
