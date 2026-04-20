--- contrib/libev/ev.c.orig	2026-01-08 13:17:41 UTC
+++ contrib/libev/ev.c
@@ -236,6 +236,9 @@
 
 #include <signal.h>
 
+#ifdef __sun
+# include <sys/statvfs.h>
+#endif
 #ifdef EV_H
 # include EV_H
 #else
@@ -4812,6 +4815,20 @@ infy_add (EV_P_ ev_stat *w)
 
       if (!fs_2625)
         w->timer.repeat = w->interval ? w->interval : DEF_STAT_INTERVAL;
+#if defined(__sun)
+      else
+        {
+          struct statvfs svfs;
+          if (statvfs (w->path, &svfs) == 0 &&
+              strcmp(svfs.f_basetype, "nfs") != 0 &&
+              strcmp(svfs.f_basetype, "smb") != 0)
+            {
+              w->timer.repeat = 0.;
+            }
+          else
+            w->timer.repeat = w->interval ? w->interval : NFS_STAT_INTERVAL;
+        }
+#else
       else if (!statfs (w->path, &sfs)
                && (sfs.f_type == 0x1373 /* devfs */
                    || sfs.f_type == 0x4006 /* fat */
@@ -4828,6 +4845,7 @@ infy_add (EV_P_ ev_stat *w)
         w->timer.repeat = 0.; /* filesystem is local, kernel new enough */
       else
         w->timer.repeat = w->interval ? w->interval : NFS_STAT_INTERVAL; /* remote, use reduced frequency */
+#endif
     }
   else
     {
