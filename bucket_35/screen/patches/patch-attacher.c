--- attacher.c.orig	2017-10-23 11:32:41 UTC
+++ attacher.c
@@ -730,7 +730,7 @@ LockTerminal()
   printf("\n");
 
   prg = getenv("LOCKPRG");
-  if (prg && strcmp(prg, "builtin") && !access(prg, X_OK))
+  if (prg && (strcmp(prg, "builtin") || strcmp(prg,"builtin-passwd")) && !access(prg, X_OK))
     {
       signal(SIGCHLD, SIG_DFL);
       debug1("lockterminal: '%s' seems executable, execl it!\n", prg);
@@ -747,7 +747,11 @@ LockTerminal()
             Panic(errno, "setuid");
 #endif
           closeallfiles(0);	/* important: /etc/shadow may be open */
-          execl(prg, "SCREEN-LOCK", NULL);
+          if (strcmp(prg,"builtin-passwd"))
+            /* use system passsword for lock */
+            execl(prg, "SCREEN-LOCK", "-p", "-n", NULL);
+          else
+            execl(prg, "SCREEN-LOCK", NULL);
           exit(errno);
         }
       if (pid == -1)
