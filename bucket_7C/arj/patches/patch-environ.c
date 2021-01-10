--- environ.c.intermediate	2021-01-10 04:42:23 UTC
+++ environ.c
@@ -58,7 +58,7 @@
   #include <sys/ioctl.h>
   #include <sys/statfs.h>
   #include <sys/statvfs.h>
- #elif defined(__FreeBSD__)||defined(__NetBSD__)
+ #elif defined(__FreeBSD__)||defined(__NetBSD__) || defined(__DragonFly__)
   #include <sys/param.h>
   #include <sys/mount.h>
  #elif defined(__QNXNTO__)
@@ -2061,7 +2061,7 @@ FILE *file_open(char *name, char *mode)
       /* ASR fix 01/10/2003 -- re-fix to handle umask 022 correctly */
       if((handle=open(name, oflag, 0644))==-1)
        return(NULL);
-      if(fcntl(handle, F_SETLK, &flk)==-1&&errno!=EINVAL)
+      if(fcntl(handle, F_SETLK, &flk)==-1&&errno!=EINVAL&&errno!=ENOTSUP)
       {
        close(handle);
        return(NULL);
