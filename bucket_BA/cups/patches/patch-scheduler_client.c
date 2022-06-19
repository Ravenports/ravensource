--- scheduler/client.c.orig	2022-05-26 06:17:21 UTC
+++ scheduler/client.c
@@ -3514,8 +3514,8 @@ pipe_command(cupsd_client_t *con,	/* I -
   * Then execute the command...
   */
 
-  if (cupsdStartProcess(command, argv, envp, infile, fds[1], CGIPipes[1],
-			-1, -1, root, DefaultProfile, NULL, &pid) < 0)
+  if (!cupsdStartProcess(command, argv, envp, infile, fds[1], CGIPipes[1],
+			 -1, -1, root, DefaultProfile, NULL, &pid))
   {
    /*
     * Error - can't fork!
