--- src/dialects/bsd/procinfo.c.orig	2013-10-07 12:11:29 UTC
+++ src/dialects/bsd/procinfo.c
@@ -63,7 +63,7 @@ void get_info(int pid, struct procinfo *
 int fill_kinfo(struct kinfo_proc *info, int pid)
 {
 	int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, pid };
-	int len = sizeof *info;
+	size_t len = sizeof *info;
 	if(sysctl(mib, 4, info, &len, 0, 0) == -1) 
 		return -1;
 	return len?0:-1;
@@ -81,12 +81,28 @@ void get_info(int pid, struct procinfo *
 	
 	if(fill_kinfo(&info, pid) == -1) return;
 	
+# if defined __FreeBSD__
+    	p->ppid  = info.ki_ppid;
+    	p->tpgid = info.ki_tpgid;
+    	p->euid  = info.ki_uid;
+    	p->stat  = info.ki_stat;
+    	strncpy(p->exec_file, info.ki_comm, EXEC_FILE);
+    	p->cterm = info.ki_tdev;
+# elif defined __DragonFly__
+    	p->ppid  = info.kp_ppid;
+    	p->tpgid = info.kp_tpgid;
+    	p->euid  = info.kp_uid;
+    	p->stat  = info.kp_stat;
+    	strncpy(p->exec_file, info.kp_comm, EXEC_FILE);
+    	p->cterm = info.kp_tdev;
+# else	
     	p->ppid = info.kp_eproc.e_ppid;
     	p->tpgid = info.kp_eproc.e_tpgid;
     	p->euid = info.kp_eproc.e_pcred.p_svuid;
     	p->stat = info.kp_proc.p_stat;
     	strncpy(p->exec_file, info.kp_proc.p_comm, EXEC_FILE);
     	p->cterm = info.kp_eproc.e_tdev;
+# endif
 	p->exec_file[EXEC_FILE] = '\0';
 }
 #endif
@@ -101,6 +117,16 @@ int get_ppid(int pid)
 	return p.ppid;
 }
 
+/*
+ * Get UID
+ */
+int proc_pid_uid(u32 pid)
+{
+	static struct procinfo p;
+	get_info((int)pid, &p);
+	return p.euid;
+}
+
 #ifdef HAVE_PROCESS_SYSCTL
 /*
  * Get terminal
@@ -122,7 +148,8 @@ int get_term(char *tty)
 int get_login_pid(char *tty)
 {
 	int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_TTY, 0};
-	int len, t, el, i, pid, cndt = -1, l;
+	int t, el, i, pid, cndt = -1, l;
+	size_t len;
 	struct kinfo_proc *info;
 	struct procinfo p;
 	
@@ -140,6 +167,29 @@ int get_login_pid(char *tty)
 	if(sysctl(mib, 4, info, &len, 0, 0) == -1)
 		return -1;
 	for(i = 0; i < el; i++) {
+# if defined __FreeBSD__
+		if(!(pid = info[i].ki_pid)) continue;
+		get_info(get_ppid(pid), &p);
+		if(p.cterm == -1 || p.cterm != t) {
+			cndt = pid;
+			l = strlen(info[i].ki_comm);
+			if(l > 1 && !strncmp("sh",info[i].ki_comm+l-2,2)) {
+				free(info);
+				return pid;
+			}
+		}
+# elif defined __DragonFly__
+		if(!(pid = info[i].kp_pid)) continue;
+		get_info(get_ppid(pid), &p);
+		if(p.cterm == -1 || p.cterm != t) {
+			cndt = pid;
+			l = strlen(info[i].kp_comm);
+			if(l > 1 && !strncmp("sh",info[i].kp_comm+l-2,2)) {
+				free(info);
+				return pid;
+			}
+		}
+# else
 		if(!(pid = info[i].kp_proc.p_pid)) continue;
 		get_info(get_ppid(pid), &p);
 		if(p.cterm == -1 || p.cterm != t) {
@@ -156,6 +206,7 @@ int get_login_pid(char *tty)
 				return pid;
 			}
 		}
+# endif
 	}
 	free(info);
 	return cndt;
@@ -167,7 +218,8 @@ int get_login_pid(char *tty)
 int get_all_info(struct kinfo_proc **info)
 {
 	int mib[3] = { CTL_KERN, KERN_PROC, KERN_PROC_ALL };
-	int len, el;
+	int el;
+	size_t len;
 
 	if(sysctl(mib, 3, 0, &len, 0, 0) == -1)
 		return 0;
@@ -237,7 +289,13 @@ char *get_cmdline(int pid)
 	bzero(buf, sizeof buf);
 	if(fill_kinfo(&info, pid) == -1)
 		return "-";
+# if defined __FreeBSD__
+	memcpy(buf, info.ki_comm, sizeof buf - 1);
+# elif defined __DragonFly__
+	memcpy(buf, info.kp_comm, sizeof buf - 1);
+# else
 	memcpy(buf, info.kp_proc.p_comm, sizeof buf - 1);
+# endif
 	if(!full_cmd) return buf;
 #ifdef HAVE_LIBKVM
 	if(!can_use_kvm) return buf;
@@ -279,48 +337,9 @@ char *get_name(int pid)
 	return p.exec_file;
 }
 
-
-/*
- * Get state and owner (effective uid) of a process
- */
-#ifdef HAVE_PROCESS_SYSCTL
-void get_state(struct process *p)
-{
-	struct procinfo pi;
-	/* state SSLEEP won't be marked in proc tree */
-	char s[] = "FR DZ";
-	get_info(p->proc->pid, &pi);
-	p->uid = pi.euid;
-	if(pi.stat == ' ') {
-		p->state = '?';
-		return;
-	}
-	p->state = s[pi.stat-1];
-}
-#else
-void get_state(struct process *p)
+int proc_getloadavg(double d[], int l)
 {
-	char buf[256];
-	struct stat s;
-	char state;
-        FILE *f;
-        snprintf(buf, sizeof buf - 6, "/proc/%d", p->proc->pid);
-	p->uid = -1;
-	if (stat(buf, &s) >= 0) p->uid = s.st_uid;  
-	strcat(buf,"/stat");
-        if (!(f = fopen(buf,"rt"))){
-               	p->state = '?';
-		return;
-	}
-        fscanf(f,"%*d %*s %c",&state);
-	fclose(f);
-	p->state = state=='S'?' ':state;
-}
-#endif
-
 #ifndef HAVE_GETLOADAVG
-int getloadavg(double d[], int l)
-{
 	FILE *f;
 	if(!(f = fopen("/proc/loadavg", "r")))
 		return -1;
@@ -330,8 +349,11 @@ int getloadavg(double d[], int l)
 	}
 	fclose(f);
 	return 0;
-}
+#else
+	return getloadavg(d, l);
 #endif
+}
+
 /* 
  * It really shouldn't be in this file.
  * Count idle time.
