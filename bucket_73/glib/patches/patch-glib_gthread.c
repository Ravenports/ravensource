--- glib/gthread.c.orig	2026-10-06 15:22:44 UTC
+++ glib/gthread.c
@@ -1187,7 +1187,7 @@ g_get_num_processors (void)
         pcore_count > 0)
       return pcore_count;
   }
-#elif defined(_SC_NPROCESSORS_ONLN) && defined(THREADS_POSIX) && defined(HAVE_PTHREAD_GETAFFINITY_NP)
+#elif defined(_SC_NPROCESSORS_ONLN) && defined(THREADS_POSIX) && defined(HAVE_PTHREAD_GETAFFINITY_NP) && defined(CPU_ZERO)
   {
     int ncores = MIN (sysconf (_SC_NPROCESSORS_ONLN), CPU_SETSIZE);
     cpu_set_t cpu_mask;
