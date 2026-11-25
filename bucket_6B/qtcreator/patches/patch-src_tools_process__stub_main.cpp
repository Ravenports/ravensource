--- src/tools/process_stub/main.cpp.orig	2026-11-20 09:56:38 UTC
+++ src/tools/process_stub/main.cpp
@@ -38,6 +38,11 @@
 #define STUB_SIGSTOP_SUSPEND
 #endif
 
+#ifdef Q_OS_UNIX
+#include <sys/ptrace.h>
+#include <sys/wait.h>
+#endif
+
 #include <iostream>
 
 static Q_LOGGING_CATEGORY(log, "qtc.process_stub", QtWarningMsg);
@@ -273,6 +278,9 @@ static void onInferiorStarted()
     // In debug mode we use the poll timer to send the pid.
     if (!debugMode)
         sendPid(inferiorId);
+#elif defined(Q_OS_FREEBSD) || defined(Q_OS_DRAGONFLY)
+    ptrace(PT_DETACH, inferiorId, 0, SIGSTOP);
+    sendPid(inferiorId);
 #elif defined(Q_OS_LINUX)
     if (debugMode) {
         qCInfo(log) << "Waiting for SIGTRAP from inferiors execve ...";
@@ -309,6 +317,11 @@ static void setupUnixInferior()
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
