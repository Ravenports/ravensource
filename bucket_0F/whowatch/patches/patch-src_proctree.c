--- src/proctree.c.orig	2026-03-28 16:48:31 UTC
+++ src/proctree.c
@@ -193,6 +193,9 @@ int update_tree(void del(void*))
 #ifdef HAVE_PROCESS_SYSCTL
 	el = get_all_info(&pi);
 	for(i = 0; i < el; i++) {
+#if defined (__DragonFly__)
+		if (pi[i].kinfo_pid < 1) continue;
+#endif
 		p = validate_proc(pi[i].kinfo_pid, ' ');
 		q = validate_proc(pi[i].kinfo_ppid, ' ');
 #else
