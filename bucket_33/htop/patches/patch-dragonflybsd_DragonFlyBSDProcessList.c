--- dragonflybsd/DragonFlyBSDProcessList.c.orig	2021-10-14 21:42:05 UTC
+++ dragonflybsd/DragonFlyBSDProcessList.c
@@ -464,7 +464,7 @@ void ProcessList_goThroughEntries(Proces
          proc->pgrp = kproc->kp_pgid;		// process group id
          proc->session = kproc->kp_sid;
          proc->st_uid = kproc->kp_uid;		// user ID
-         proc->processor = kproc->kp_lwp.kl_origcpu;
+         proc->processor = kproc->kp_lwp.kl_cpuid;
          proc->starttime_ctime = kproc->kp_start.tv_sec;
          Process_fillStarttimeBuffer(proc);
          proc->user = UsersTable_getRef(super->usersTable, proc->st_uid);
@@ -603,6 +603,24 @@ void ProcessList_goThroughEntries(Proces
    }
 }
 
+char **DragonFlyBSDGet_env(pid_t pid) {
+
+   kvm_t *kd;
+   struct kinfo_proc *kp;
+   char **env;
+   char errbuf[_POSIX2_LINE_MAX];
+   int count;
+
+   kd = kvm_openfiles(NULL, "/dev/null", NULL, 0, errbuf);
+   if (kd == NULL)
+      return NULL;
+
+   kp = kvm_getprocs(kd, KERN_PROC_PID, pid, &count);
+   env = kvm_getenvv(kd, kp, 0);
+   kvm_close(kd);
+   return env;
+}
+
 bool ProcessList_isCPUonline(const ProcessList* super, unsigned int id) {
    assert(id < super->existingCPUs);
 
