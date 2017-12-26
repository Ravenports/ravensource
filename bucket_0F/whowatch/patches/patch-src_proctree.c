--- src/proctree.c.orig	2013-10-07 12:11:29 UTC
+++ src/proctree.c
@@ -172,8 +172,17 @@ int update_tree(void del(void*))
 #ifdef HAVE_PROCESS_SYSCTL
 	el = get_all_info(&pi);
 	for(i = 0; i < el; i++) {
+# if defined __FreeBSD__
+		p = validate_proc(pi[i].ki_pid, ' ');
+		q = validate_proc(pi[i].ki_ppid, ' ');
+# elif defined __DragonFly__
+		if (pi[i].kp_pid < 1) continue;
+		p = validate_proc(pi[i].kp_pid, ' ');
+		q = validate_proc(pi[i].kp_ppid, ' ');
+# else
 		p = validate_proc(pi[i].kp_proc.p_pid, ' ');
 		q = validate_proc(pi[i].kp_eproc.e_ppid, ' ');
+# endif
 #else
 
 	d=opendir(PROCDIR);
