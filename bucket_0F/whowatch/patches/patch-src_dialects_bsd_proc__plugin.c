--- src/dialects/bsd/proc_plugin.c.orig	2013-10-07 12:11:29 UTC
+++ src/dialects/bsd/proc_plugin.c
@@ -381,7 +381,7 @@ FOUND:
 	boot_time = (time_t) c;
 }		
 
-#include <asm/param.h>	// for HZ
+#define HZ	60
 
 static void proc_starttime(int pid, char *name)
 {
@@ -414,7 +414,7 @@ struct proc_detail_t proc_details_t[] =
 };
 
 
-void builtin_proc_draw(void *p)
+void eproc(void *p)
 {
         int i;
 	int pid = *(int*)p;
@@ -499,7 +499,7 @@ static void get_cpu_info()
 	print("%s", buf);
 }
 
-void builtin_sys_draw(void *unused)
+void esys(void *unused)
 {
 	int c;
 	print("BOOT TIME: ");
