--- src/file/priority.cpp.orig	2026-11-07 15:23:20 UTC
+++ src/file/priority.cpp
@@ -17,13 +17,13 @@
 #include <sys/syscall.h>
 #include <unistd.h>
 
-#ifdef SYS_ioprio_set
+#ifdef __linux__
 #include <linux/ioprio.h>
 #endif
 
 bool lowerIOPriority()
 {
-#ifdef SYS_ioprio_set
+#if 0
     if (syscall(SYS_ioprio_set, IOPRIO_WHO_PROCESS, 0, ioprio_value(IOPRIO_CLASS_IDLE, 0, IOPRIO_HINT_NONE)) >= 0) {
         return true;
     }
