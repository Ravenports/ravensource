--- scheduler/client.c.orig	2018-12-07 19:41:56 UTC
+++ scheduler/client.c
@@ -3816,8 +3816,8 @@ pipe_command(cupsd_client_t *con,	/* I -
   * Then execute the command...
   */
 
-  if (cupsdStartProcess(command, argv, envp, infile, fds[1], CGIPipes[1],
-			-1, -1, root, DefaultProfile, NULL, &pid) < 0)
+  if (!cupsdStartProcess(command, argv, envp, infile, fds[1], CGIPipes[1],
+			 -1, -1, root, DefaultProfile, NULL, &pid))
   {
    /*
     * Error - can't fork!
