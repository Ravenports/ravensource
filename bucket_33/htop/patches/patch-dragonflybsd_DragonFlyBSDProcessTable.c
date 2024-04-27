--- dragonflybsd/DragonFlyBSDProcessTable.c.orig	2024-01-10 09:54:15 UTC
+++ dragonflybsd/DragonFlyBSDProcessTable.c
@@ -37,7 +37,7 @@ ProcessTable* ProcessTable_new(Machine*
 }
 
 void ProcessTable_delete(Object* cast) {
-   const DragonFlyBSDProcessTable* this = (DragonFlyBSDProcessTable*) cast;
+   DragonFlyBSDProcessTable* this = (DragonFlyBSDProcessTable*) cast;
    ProcessTable_done(&this->super);
    free(this);
 }
@@ -130,8 +130,8 @@ static void DragonFlyBSDProcessTable_upd
 }
 
 void ProcessTable_goThroughEntries(ProcessTable* super) {
-   const Machine* host = super->host;
-   const DragonFlyMachine* dhost = (const DragonFlyMachine*) host;
+   const Machine* host = super->super.host;
+   const DragonFlyBSDMachine* dhost = (const DragonFlyBSDMachine*) host;
    const Settings* settings = host->settings;
 
    bool hideKernelThreads = settings->hideKernelThreads;
@@ -168,7 +168,7 @@ void ProcessTable_goThroughEntries(Proce
          proc->pgrp = kproc->kp_pgid;		// process group id
          proc->session = kproc->kp_sid;
          proc->st_uid = kproc->kp_uid;		// user ID
-         proc->processor = kproc->kp_lwp.kl_origcpu;
+         proc->processor = kproc->kp_lwp.kl_cpuid;
          proc->starttime_ctime = kproc->kp_start.tv_sec;
          Process_fillStarttimeBuffer(proc);
          proc->user = UsersTable_getRef(host->usersTable, proc->st_uid);
@@ -216,7 +216,7 @@ void ProcessTable_goThroughEntries(Proce
       proc->time = (kproc->kp_lwp.kl_uticks + kproc->kp_lwp.kl_sticks + kproc->kp_lwp.kl_iticks) / 10000;
 
       proc->percent_cpu = 100.0 * ((double)kproc->kp_lwp.kl_pctcpu / (double)dhost->kernelFScale);
-      proc->percent_mem = 100.0 * proc->m_resident / (double)(super->totalMem);
+      proc->percent_mem = 100.0 * proc->m_resident / (double)(super->super.host->totalMem);
       Process_updateCPUFieldWidths(proc->percent_cpu);
 
       if (proc->percent_cpu > 0.1) {
