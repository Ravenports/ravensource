--- src/master/main.c.orig	2025-01-24 07:08:40 UTC
+++ src/master/main.c
@@ -919,6 +919,8 @@ int main(int argc, char *argv[])
 	if (!i_failure_have_stdout_logs() &&
 	    dup2(dev_null_fd, STDOUT_FILENO) < 0)
 		i_fatal("dup2(dev_null_fd) failed: %m");
+	if (!foreground && dup2(dev_null_fd, STDERR_FILENO) < 0)
+		i_fatal("dup2(dev_null_fd) failed: %m");
 
 	startup_early_errors_flush();
 	i_get_failure_handlers(&orig_fatal_callback, &orig_error_callback,
