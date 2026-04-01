--- glib/glib-unix.c.orig	2026-03-16 13:53:50 UTC
+++ glib/glib-unix.c
@@ -50,6 +50,12 @@
 #include <stdlib.h>   /* for fdwalk */
 #include <string.h>
 #include <sys/types.h>
+#if defined __DragonFly__ || defined __NetBSD__
+#include <sys/param.h>  /* for MAXPATHLEN */
+#endif
+#ifdef __sun
+#define _POSIX_PTHREAD_SEMANTICS 1
+#endif
 #include <pwd.h>
 #include <unistd.h>
 
@@ -967,7 +973,7 @@ g_unix_fd_query_path (int      fd,
   g_free (proc_path);
 
   return g_steal_pointer (&path);
-#elif defined (__FreeBSD__) || defined(__DragonFly__)
+#elif defined (__FreeBSD__)
   struct kinfo_file kf = {0};
 
   kf.kf_structsize = sizeof (kf);
@@ -982,7 +988,7 @@ g_unix_fd_query_path (int      fd,
     }
 
   return g_strdup (kf.kf_path);
-#elif defined (__APPLE__) || defined (__NetBSD__) || defined (__OpenBSD__)
+#elif defined (__APPLE__) || defined (__NetBSD__) || defined (__OpenBSD__) || defined (__DragonFly__)
   char file_path[MAXPATHLEN] = {0};
 
   if (fcntl (fd, F_GETPATH, file_path) < 0)
