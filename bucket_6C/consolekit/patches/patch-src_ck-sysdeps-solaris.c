--- src/ck-sysdeps-solaris.c.orig	2023-08-11 16:26:44 UTC
+++ src/ck-sysdeps-solaris.c
@@ -129,7 +129,7 @@ ck_process_stat_get_tty (CkProcessStat *
 static int
 get_system_vt_major ()
 {
-        static      ret = -1;
+        static int  ret = -1;
         struct stat st;
         int         res;
 
