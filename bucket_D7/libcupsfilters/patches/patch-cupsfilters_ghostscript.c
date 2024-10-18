--- cupsfilters/ghostscript.c.orig	2024-10-17 20:58:08 UTC
+++ cupsfilters/ghostscript.c
@@ -610,7 +610,13 @@ gs_spawn (const char *filename,
     }
 
     // Execute Ghostscript command line ...
+#if defined(__DragonFly__) || defined(__FreeBSD__)
+    extern char **environ;
+    environ = envp;
+    execvp(filename, gsargv);
+#else
     execvpe(filename, gsargv, envp);
+#endif
     if (log) log(ld, CF_LOGLEVEL_ERROR,
 		 "cfFilterGhostscript: Unable to launch Ghostscript: %s: %s",
 		 filename, strerror(errno));
