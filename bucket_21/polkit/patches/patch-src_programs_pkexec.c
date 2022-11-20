Avoid conflict with SunOS function.
Provide solaris header for LOG_AUTHPRIV

--- src/programs/pkexec.c.orig	2022-10-26 12:12:24 UTC
+++ src/programs/pkexec.c
@@ -45,6 +45,9 @@
 
 #include <syslog.h>
 #include <stdarg.h>
+#ifdef HAVE_SOLARIS
+#include <netinet/ip_compat.h>
+#endif
 
 #include <polkit/polkit.h>
 #define POLKIT_AGENT_I_KNOW_API_IS_SUBJECT_TO_CHANGE
@@ -245,7 +248,7 @@ set_close_on_exec (gint     fd,
 }
 
 static gboolean
-fdwalk (FdCallback callback,
+gfdwalk (FdCallback callback,
         gpointer   user_data)
 {
   gint fd;
@@ -941,7 +944,7 @@ main (int argc, char *argv[])
     }
 
   /* set close_on_exec on all file descriptors except stdin, stdout, stderr */
-  if (!fdwalk (set_close_on_exec, GINT_TO_POINTER (3)))
+  if (!gfdwalk (set_close_on_exec, GINT_TO_POINTER (3)))
     {
       g_printerr ("Error setting close-on-exec for file desriptors\n");
       goto out;
