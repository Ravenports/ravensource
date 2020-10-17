$OpenBSD: patch-main_c,v 1.1 2013/06/01 21:06:20 kurt Exp $
--- main.c.orig	2020-05-02 04:28:05 UTC
+++ main.c
@@ -833,7 +833,9 @@ main(int argc, char **argv, char **envp)
     mySignal(SIGPIPE, SigPipe);
 #endif
 
-    orig_GC_warn_proc = GC_set_warn_proc(wrap_GC_warn_proc);
+    orig_GC_warn_proc = GC_get_warn_proc();
+    GC_set_warn_proc(wrap_GC_warn_proc);
+
     err_msg = Strnew();
     if (load_argc == 0) {
 	/* no URL specified */
