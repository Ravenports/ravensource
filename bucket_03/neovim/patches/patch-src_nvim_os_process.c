--- src/nvim/os/process.c.orig	2023-09-07 10:26:08 UTC
+++ src/nvim/os/process.c
@@ -23,13 +23,13 @@
 # include "nvim/api/private/helpers.h"
 #endif
 
-#if defined(__FreeBSD__)  // XXX: OpenBSD ?
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 # include <string.h>
 # include <sys/types.h>
 # include <sys/user.h>
 #endif
 
-#if defined(__NetBSD__) || defined(__OpenBSD__)
+#if defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
 # include <sys/param.h>
 #endif
 
@@ -150,6 +150,9 @@ int os_proc_children(int ppid, int **pro
 # elif defined(__FreeBSD__)
 #  define KP_PID(o) o.ki_pid
 #  define KP_PPID(o) o.ki_ppid
+# elif defined(__DragonFly__)
+#  define KP_PID(o)  o.kp_pid
+#  define KP_PPID(o) o.kp_ppid
 # else
 #  define KP_PID(o) o.p_pid
 #  define KP_PPID(o) o.p_ppid
