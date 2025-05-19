--- src/tools/process_stub/main.cpp.orig	2025-04-10 08:57:18 UTC
+++ src/tools/process_stub/main.cpp
@@ -28,6 +28,11 @@
 #include <sys/prctl.h>
 #endif
 
+#ifdef Q_OS_UNIX
+#include <sys/ptrace.h>
+#include <sys/wait.h>
+#endif
+
 #include <iostream>
 
 Q_LOGGING_CATEGORY(log, "qtc.process_stub", QtWarningMsg);
@@ -254,6 +259,9 @@ void onInferiorStarted()
     // In debug mode we use the poll timer to send the pid.
     if (!debugMode)
         sendPid(inferiorId);
+#elif defined(Q_OS_FREEBSD) || defined(Q_OS_DRAGONFLY)
+    ptrace(PT_DETACH, inferiorId, 0, SIGSTOP);
+    sendPid(inferiorId);
 #elif defined(Q_OS_LINUX)
     if (debugMode) {
         qCInfo(log) << "Waiting for SIGTRAP from inferiors execve ...";
@@ -288,6 +296,11 @@ void setupUnixInferior()
             // Suspend ourselves ...
             raise(SIGSTOP);
         });
+#elif defined(Q_OS_FREEBSD) || defined(Q_OS_DRAGONFLY)
+        // PT_TRACE_ME will stop execution of the child process as soon as execve is called.
+        inferiorProcess.setChildProcessModifier([] {
+            ptrace(PT_TRACE_ME, 0, 0, 0);
+        });
 #elif defined(Q_OS_LINUX)
         // PTRACE_TRACEME will stop execution of the child process as soon as execve is called.
         inferiorProcess.setChildProcessModifier([] {
