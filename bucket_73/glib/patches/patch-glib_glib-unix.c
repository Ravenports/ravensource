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
 
@@ -73,6 +79,9 @@
 #if defined (__FreeBSD__)
 #include <sys/user.h>
 #endif  /* defined (__FreeBSD__ )*/
+#if defined (__MidnightBSD__)
+#include <sys/sysctl.h>
+#endif
 
 G_STATIC_ASSERT (sizeof (ssize_t) == GLIB_SIZEOF_SSIZE_T);
 G_STATIC_ASSERT (G_ALIGNOF (gssize) == G_ALIGNOF (ssize_t));
@@ -967,7 +976,36 @@ g_unix_fd_query_path (int      fd,
   g_free (proc_path);
 
   return g_steal_pointer (&path);
-#elif defined (__FreeBSD__) || defined(__DragonFly__)
+#elif defined (__MidnightBSD__)
+ char file_path[MAXPATHLEN] = {0};
+  size_t len = sizeof (struct kinfo_file);
+  struct kinfo_file kif;
+
+  // MIB for a specific FD: [Kernel, Process, File Descriptor, PID, FD]
+  int mib[5] = { CTL_KERN, KERN_PROC, KERN_PROC_FILEDESC, getpid(), fd };
+
+  // Query the kernel for just this specific FD
+  if (sysctl (mib, 5, &kif, &len, NULL, 0) < 0)
+    {
+      int errsv = errno;
+      g_set_error (error, G_FILE_ERROR, g_file_error_from_errno (errsv),
+                   "Error querying file information for FD %d: %s",
+                   fd, g_strerror (errsv));
+      return NULL;
+    }
+
+  // Ensure the path isn't empty (e.g., if it's a pipe or socket)
+  if (len == 0 || kif.kf_path[0] == '\0')
+    {
+      g_set_error (error, G_FILE_ERROR, g_file_error_from_errno (EBADF),
+                   "No path available for FD %d", fd);
+      return NULL;
+    }
+
+  g_strlcpy (file_path, kif.kf_path, sizeof (file_path));
+
+  return g_strdup (file_path);
+#elif defined (__FreeBSD__)
   struct kinfo_file kf = {0};
 
   kf.kf_structsize = sizeof (kf);
@@ -982,7 +1020,7 @@ g_unix_fd_query_path (int      fd,
     }
 
   return g_strdup (kf.kf_path);
-#elif defined (__APPLE__) || defined (__NetBSD__) || defined (__OpenBSD__)
+#elif defined (__APPLE__) || defined (__NetBSD__) || defined (__OpenBSD__) || defined (__DragonFly__)
   char file_path[MAXPATHLEN] = {0};
 
   if (fcntl (fd, F_GETPATH, file_path) < 0)
