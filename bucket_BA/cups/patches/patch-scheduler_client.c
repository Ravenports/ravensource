--- scheduler/client.c.orig	2020-04-27 18:04:29 UTC
+++ scheduler/client.c
@@ -3519,8 +3519,8 @@ pipe_command(cupsd_client_t *con,	/* I -
   * Then execute the command...
   */
 
-  if (cupsdStartProcess(command, argv, envp, infile, fds[1], CGIPipes[1],
-			-1, -1, root, DefaultProfile, NULL, &pid) < 0)
+  if (!cupsdStartProcess(command, argv, envp, infile, fds[1], CGIPipes[1],
+			 -1, -1, root, DefaultProfile, NULL, &pid))
   {
    /*
     * Error - can't fork!
