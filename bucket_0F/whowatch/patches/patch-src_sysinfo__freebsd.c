--- src/sysinfo_freebsd.c.orig	2026-03-28 16:48:31 UTC
+++ src/sysinfo_freebsd.c
@@ -2,7 +2,9 @@
 #include "sysinfo.h"
 #include <devinfo.h>
 #include <kvm.h>
+#if defined(__FreeBSD__)
 #include <libgeom.h>
+#endif
 #include <libutil.h>
 #include <paths.h>
 #include <stdint.h>
@@ -257,6 +259,7 @@ static struct flaglist {
         .flag = VFCF_UNICODE,
         .str = "unicode",
     },
+#if defined(__FreeBSD__)
     {
         .flag = VFCF_JAIL,
         .str = "jail",
@@ -265,6 +268,7 @@ static struct flaglist {
         .flag = VFCF_DELEGADMIN,
         .str = "delegated-administration",
     },
+#endif
 };
 
 static const char *fmt_flags(int flags) {
@@ -298,6 +302,7 @@ void sys_filesystems_info() {
     return;
   }
 
+#if defined(__FreeBSD__)
   println("%-20.20s  %s\n", "Filesystem", "Flags");
   println("-------------------- -------------------\n");
   size_t cnt = buf / sizeof(struct xvfsconf);
@@ -306,9 +311,11 @@ void sys_filesystems_info() {
     println("%-20.20s %s\n", xvfsp[i].vfc_name, fmt_flags(xvfsp[i].vfc_flags));
   }
   free(xvfsp);
+#endif
 }
 
 void sys_partitions_info() {
+#if defined(__FreeBSD__)
   struct gmesh mesh;
   struct gclass *classp;
   struct ggeom *geomp;
@@ -333,6 +340,9 @@ void sys_partitions_info() {
     }
   }
   geom_deletetree(&mesh);
+#else
+  return;
+#endif
 }
 
 static int print_device(struct devinfo_dev *dev, void *arg) {
@@ -378,7 +388,11 @@ time_t sys_start_time(int pid) {
   if (len == 0)
     return -1;
 
+#if defined(__FreeBSD__)
   return kp.ki_start.tv_sec;
+#else
+  return kp.kp_start.tv_sec;
+#endif
 }
 
 void sys_proc_exe(int pid) {
@@ -398,6 +412,7 @@ void sys_proc_exe(int pid) {
   print("%s\n", path);
 }
 
+#if defined(__FreeBSD__)
 #include <libprocstat.h>
 
 void sys_proc_root(int pid) {
@@ -583,3 +598,9 @@ void sys_proc_fds(pid_t pid) {
   procstat_freeprocs(ps, kp);
   procstat_close(ps);
 }
+#else
+void sys_proc_root(int pid) {return;}
+void sys_proc_cwd(int pid) {return;}
+void sys_proc_status(int pid) {return;}
+void sys_proc_fds(pid_t pid) {return;}
+#endif
