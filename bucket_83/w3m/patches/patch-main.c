--- main.c.orig	2017-01-06 14:20:43 UTC
+++ main.c
@@ -889,12 +889,8 @@ main(int argc, char **argv, char **envp)
     mySignal(SIGPIPE, SigPipe);
 #endif
 
-#if GC_VERSION_MAJOR >= 7 && GC_VERSION_MINOR >= 2
     orig_GC_warn_proc = GC_get_warn_proc();
     GC_set_warn_proc(wrap_GC_warn_proc);
-#else
-    orig_GC_warn_proc = GC_set_warn_proc(wrap_GC_warn_proc);
-#endif
     err_msg = Strnew();
     if (load_argc == 0) {
 	/* no URL specified */
