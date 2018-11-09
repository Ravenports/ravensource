--- scheduler/subscriptions.c.orig	2018-11-08 13:49:36 UTC
+++ scheduler/subscriptions.c
@@ -1561,8 +1561,8 @@ cupsd_start_notifier(
   * Create the notifier process...
   */
 
-  if (cupsdStartProcess(command, argv, envp, fds[0], -1, NotifierPipes[1],
-			-1, -1, 0, DefaultProfile, NULL, &pid) < 0)
+  if (!cupsdStartProcess(command, argv, envp, fds[0], -1, NotifierPipes[1],
+			 -1, -1, 0, DefaultProfile, NULL, &pid))
   {
    /*
     * Error - can't fork!
