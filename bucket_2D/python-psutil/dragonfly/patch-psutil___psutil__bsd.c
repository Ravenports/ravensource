--- psutil/_psutil_bsd.c.orig	2020-10-23 17:57:58 UTC
+++ psutil/_psutil_bsd.c
@@ -19,6 +19,7 @@
     #define _KMEMUSER
 #endif
 
+#include <netinet/in.h>
 #include <Python.h>
 #include <assert.h>
 #include <errno.h>
@@ -41,7 +42,6 @@
 #include <sys/un.h>
 #include <sys/unpcb.h>
 // for xinpcb struct
-#include <netinet/in.h>
 #include <netinet/in_systm.h>
 #include <netinet/ip.h>
 #include <netinet/in_pcb.h>
@@ -94,6 +94,10 @@
     #ifndef DTYPE_VNODE
         #define DTYPE_VNODE 1
     #endif
+#elif PSUTIL_DRAGONFLY
+    #include "arch/bsd/dragonfly.h"
+
+    #include <utmpx.h>
 #endif
 
 
@@ -134,6 +138,8 @@ psutil_pids(PyObject *self, PyObject *ar
         for (idx = 0; idx < num_processes; idx++) {
 #ifdef PSUTIL_FREEBSD
             py_pid = PyLong_FromPid(proclist->ki_pid);
+#elif defined(PSUTIL_DRAGONFLY)
+            py_pid = PyLong_FromPid(proclist->kp_pid);
 #elif defined(PSUTIL_OPENBSD) || defined(PSUTIL_NETBSD)
             py_pid = PyLong_FromPid(proclist->p_pid);
 #endif
@@ -203,6 +209,8 @@ psutil_proc_oneshot_info(PyObject *self,
     // Process
 #ifdef PSUTIL_FREEBSD
     sprintf(str, "%s", kp.ki_comm);
+#elif defined(PSUTIL_DRAGONFLY)
+    sprintf(str, "%s", kp.kp_comm);
 #elif defined(PSUTIL_OPENBSD) || defined(PSUTIL_NETBSD)
     sprintf(str, "%s", kp.p_comm);
 #endif
@@ -222,6 +230,12 @@ psutil_proc_oneshot_info(PyObject *self,
     memtext = (long)kp.ki_tsize * pagesize;
     memdata = (long)kp.ki_dsize * pagesize;
     memstack = (long)kp.ki_ssize * pagesize;
+#elif PSUTIL_DRAGONFLY
+    rss = (long)kp.kp_vm_rssize * pagesize;
+    vms = (long)kp.kp_vm_map_size;
+    memtext = (long)kp.kp_vm_tsize * pagesize;
+    memdata = (long)kp.kp_vm_dsize * pagesize;
+    memstack = (long)kp.kp_vm_ssize * pagesize;
 #else
     rss = (long)kp.p_vm_rssize * pagesize;
     #ifdef PSUTIL_OPENBSD
@@ -259,6 +273,8 @@ psutil_proc_oneshot_info(PyObject *self,
 
 #ifdef PSUTIL_FREEBSD
     py_ppid = PyLong_FromPid(kp.ki_ppid);
+#elif defined(PSUTIL_DRAGONFLY)
+    py_ppid = PyLong_FromPid(kp.kp_ppid);
 #elif defined(PSUTIL_OPENBSD) || defined(PSUTIL_NETBSD)
     py_ppid = PyLong_FromPid(kp.p_ppid);
 #else
@@ -368,6 +384,8 @@ psutil_proc_name(PyObject *self, PyObjec
 
 #ifdef PSUTIL_FREEBSD
     sprintf(str, "%s", kp.ki_comm);
+#elif defined(PSUTIL_DRAGONFLY)
+    sprintf(str, "%s", kp.kp_comm);
 #elif defined(PSUTIL_OPENBSD) || defined(PSUTIL_NETBSD)
     sprintf(str, "%s", kp.p_comm);
 #endif
@@ -411,7 +429,7 @@ psutil_proc_environ(PyObject *self, PyOb
     if (!PyArg_ParseTuple(args, "l", &pid))
         return NULL;
 
-#if defined(PSUTIL_FREEBSD)
+#if defined(PSUTIL_FREEBSD) || defined(PSUTIL_DRAGONFLY)
     kd = kvm_openfiles(NULL, "/dev/null", NULL, 0, errbuf);
 #else
     kd = kvm_openfiles(NULL, NULL, NULL, KVM_NO_FILES, errbuf);
@@ -425,7 +443,7 @@ psutil_proc_environ(PyObject *self, PyOb
     if (!py_retdict)
         goto error;
 
-#if defined(PSUTIL_FREEBSD)
+#if defined(PSUTIL_FREEBSD) || defined(PSUTIL_DRAGONFLY)
     p = kvm_getprocs(kd, KERN_PROC_PID, pid, &cnt);
 #elif defined(PSUTIL_OPENBSD)
     p = kvm_getprocs(kd, KERN_PROC_PID, pid, sizeof(*p), &cnt);
@@ -460,6 +478,8 @@ psutil_proc_environ(PyObject *self, PyOb
 #else
     if ((p)->ki_flag & P_SYSTEM) {
 #endif
+#elif defined(PSUTIL_DRAGONFLY)
+    if ((p)->kp_flags & P_SYSTEM) {
 #elif defined(PSUTIL_NETBSD)
     if ((p)->p_stat == SZOMB) {
 #elif defined(PSUTIL_OPENBSD)
