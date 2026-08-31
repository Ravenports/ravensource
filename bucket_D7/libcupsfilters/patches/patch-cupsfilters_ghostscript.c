--- cupsfilters/ghostscript.c.orig	2026-08-11 10:31:11 UTC
+++ cupsfilters/ghostscript.c
@@ -671,7 +671,13 @@ gs_spawn (const char *filename,
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
