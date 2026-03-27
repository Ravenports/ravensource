--- src/master/main.c.orig	2026-03-27 06:57:10 UTC
+++ src/master/main.c
@@ -933,6 +933,8 @@ int main(int argc, char *argv[])
 	if (!i_failure_have_stdout_logs() &&
 	    dup2(dev_null_fd, STDOUT_FILENO) < 0)
 		i_fatal("dup2(dev_null_fd) failed: %m");
+	if (!foreground && dup2(dev_null_fd, STDERR_FILENO) < 0)
+		i_fatal("dup2(dev_null_fd) failed: %m");
 
 	startup_early_errors_flush();
 	i_get_failure_handlers(&orig_fatal_callback, &orig_error_callback,
