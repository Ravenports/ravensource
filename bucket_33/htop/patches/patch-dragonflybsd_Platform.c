--- dragonflybsd/Platform.c.orig	2025-03-05 18:24:21 UTC
+++ dragonflybsd/Platform.c
@@ -239,9 +239,33 @@ void Platform_setSwapValues(Meter* this)
 }
 
 char* Platform_getProcessEnv(pid_t pid) {
-   // TODO
-   (void)pid;  // prevent unused warning
-   return NULL;
+   char *env = NULL, **fenv = NULL, *ptr = NULL;
+   size_t size = 0;
+   kvm_t *kd;
+   struct kinfo_proc *kp;
+   char errbuf[_POSIX2_LINE_MAX];
+   int count;
+
+   kd = kvm_openfiles(NULL, "/dev/null", NULL, 0, errbuf);
+   if (kd == NULL)
+      return NULL;
+
+   kp = kvm_getprocs(kd, KERN_PROC_PID, pid, &count);
+   fenv = kvm_getenvv(kd, kp, 0);
+   kvm_close(kd);
+
+   if (fenv) {
+      ptr = fenv[0];
+      while (ptr && *ptr) {
+         size += strlen(ptr) + 1;
+         ptr += strlen(ptr) + 1;
+      }
+      env = xMalloc(size+2);
+      memcpy(env, fenv[0], size);
+      env[size] = 0;
+      env[size+1] = 0;
+   }
+   return env;
 }
 
 FileLocks_ProcessData* Platform_getProcessLocks(pid_t pid) {
