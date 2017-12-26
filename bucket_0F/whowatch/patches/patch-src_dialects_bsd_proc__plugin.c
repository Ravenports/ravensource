--- src/dialects/bsd/proc_plugin.c.orig	2013-10-07 12:11:29 UTC
+++ src/dialects/bsd/proc_plugin.c
@@ -18,9 +18,15 @@ extern int can_use_kvm;
 #define elemof(x)	(sizeof (x) / sizeof*(x))
 #define endof(x)	((x) + elemof(x))
 
-static inline void no_info(void)
+#define CR	1
+#define NO_CR	0
+
+static inline void no_info(int newline)
 {
-	println("Information unavailable.");
+	if (newline)
+		println("Information unavailable.\n");
+	else
+		println("Information unavailable.");
 }
 
 static inline char *_read_link(const char *path)
@@ -39,7 +45,7 @@ static void read_link(int pid, char *nam
 	snprintf(pbuf, sizeof pbuf, "/proc/%d/%s", pid, name); 
 	v = _read_link(pbuf);
 	if(!v) {
-		no_info();
+		no_info(CR);
 		return;
 	}
 	println(v);
@@ -241,7 +247,7 @@ void open_fds(int pid, char *name)
 	snprintf(buf, sizeof buf, "/proc/%d/fd", pid);
 	d = opendir(buf);
 	if(!d) {
-		no_info();
+		no_info(CR);
 		return;
 	}
 	if(!count || ticks - count >= 2) {
@@ -256,7 +262,7 @@ void open_fds(int pid, char *name)
 		print("%s - ", dn->d_name);
 		snprintf(buf, sizeof buf, "/proc/%d/fd/%s", pid, dn->d_name);
 		s = _read_link(buf);
-		if(!s) no_info();
+		if(!s) no_info(CR);
 		else {
 			if(!strncmp("socket:[", s, 8) && show_net_conn(s+8));
 			else print("%s", s);
@@ -306,7 +312,7 @@ static void read_proc_file(char *name, c
 	if(end) elen = strlen(end);
 	f = fopen(name, "r");
 	if(!f) {
-		no_info();
+		no_info(NO_CR);
 		return;
 	}
 	if(!start) ok = 1;
@@ -319,7 +325,7 @@ static void read_proc_file(char *name, c
 		newln();
 	}
 END:	
-	if(!ok) no_info();
+	if(!ok) no_info(CR);
 	fclose(f);
 }	
 
@@ -381,7 +387,7 @@ FOUND:
 	boot_time = (time_t) c;
 }		
 
-#include <asm/param.h>	// for HZ
+#define HZ	60
 
 static void proc_starttime(int pid, char *name)
 {
@@ -389,7 +395,7 @@ static void proc_starttime(int pid, char
 	char *s;
 	i = p_start_time(pid);
 	if(i == -1 || !boot_time) {
-		no_info();
+		no_info(CR);
 		return;
 	}
 	sec = boot_time + i/HZ;
@@ -414,7 +420,7 @@ struct proc_detail_t proc_details_t[] =
 };
 
 
-void builtin_proc_draw(void *p)
+void eproc(void *p)
 {
         int i;
 	int pid = *(int*)p;
@@ -431,7 +437,7 @@ void builtin_proc_draw(void *p)
 static inline void print_boot_time(void)
 {
 	if(boot_time) print("%s",ctime(&boot_time));
-	else no_info();
+	else no_info(CR);
 }
 
 struct cpu_info_t {
@@ -488,7 +494,10 @@ static void get_cpu_info()
 {
 	char buf[64];
 	unsigned long z;
-	if(fill_cpu_info() == -1) no_info();
+	if(fill_cpu_info() == -1) {
+		no_info(CR);
+		return;
+	}
 	z = eff_info.u_mode + eff_info.nice + eff_info.s_mode + eff_info.idle;
 	snprintf(buf, sizeof buf, "%.1f%% user %.1f%% sys %.1f%% nice %.1f%% idle\n",
 		prcnt(eff_info.u_mode, z),
@@ -499,37 +508,37 @@ static void get_cpu_info()
 	print("%s", buf);
 }
 
-void builtin_sys_draw(void *unused)
+void esys(void *unused)
 {
 	int c;
-	print("BOOT TIME: ");
+	println("     BOOT TIME: ");
 	print_boot_time();
-	print("CPU: ");
+	println("           CPU: ");
 	get_cpu_info();
-	println("MEMORY:");
+	println("        MEMORY: ");
 	read_proc_file("/proc/meminfo", "MemTotal:", 0);
-	title("USED FILES: ");
+	println("\n    USED FILES: ");
 	c = read_file_pos("/proc/sys/fs/file-nr", 2);
-	if(c == -1) no_info();
+	if(c == -1) no_info(CR);
 	else println("%d", c);
-	print("USED INODES: ");
+	println("   USED INODES: ");
 	c = read_file_pos("/proc/sys/fs/inode-nr", 2);
-	if(c == -1) no_info();
+	if(c == -1) no_info(CR);
 	else println("%d", c);
 	
-	print("MAX FILES: ");
+	println("     MAX FILES: ");
 	read_proc_file("/proc/sys/fs/file-max", 0, 0);
-	print("MAX INODES: ");
+	println("\n    MAX INODES: ");
 	read_proc_file("/proc/sys/fs/inode-max", 0, 0);
-	println("\nSTAT:");
+	println("\n          STAT: ");
 	read_proc_file("/proc/stat", "cpu", "intr");
-	println("\nLOADED MODULES:");
+	println("\nLOADED MODULES: ");
 	read_proc_file("/proc/modules", 0, 0);
-	println("\nFILESYSTEMS:");
+	println("\n   FILESYSTEMS: ");
 	read_proc_file("/proc/filesystems", 0, 0);
-	println("\nPARTITIONS:");
+	println("\n    PARTITIONS: ");
 	read_proc_file("/proc/partitions", 0, 0);
-	println("\nDEVICES:");
+	println("\n       DEVICES: ");
 	read_proc_file("/proc/devices", 0, 0);
-}	
+}
 
