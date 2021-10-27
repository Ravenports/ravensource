--- environ.c.orig	2021-10-27 00:22:50 UTC
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
@@ -2289,7 +2289,7 @@ unsigned long file_getfree(char *name)
   else
    return((LONG_MAX/(spclu*bps)<fclu)?LONG_MAX:spclu*bps*fclu);
  #elif TARGET==UNIX
-  #if defined(__QNXNTO__)||defined(__sco__)||defined(SUNOS)
+  #if defined(__QNXNTO__)||defined(__sco__)||defined(SUNOS) || defined(__NetBSD__)
    struct statvfs vfs;
 
    if(statvfs(name, &vfs)==-1)
@@ -3008,7 +3008,7 @@ void get_exe_name(char *dest, char *arg)
     they are missing altogether, the corresponding code will gracefully
     terminate. */
  #if SFX_LEVEL==ARJ
-  strcpy(dest, "/usr/local/bin/arj");
+  strcpy(dest, "@PREFIX@/bin/arj");
  #elif SFX_LEVEL==ARJSFXV
   strcpy(dest, "./arjsfxv");
  #elif SFX_LEVEL==ARJSFX
@@ -3016,7 +3016,7 @@ void get_exe_name(char *dest, char *arg)
  #elif SFX_LEVEL==ARJSFXJR
   strcpy(dest, "./arjsfxjr");
  #elif defined(REARJ)
-  strcpy(dest, "/usr/local/bin/rearj");
+  strcpy(dest, "@PREFIX@/bin/rearj");
  #else
   dest[0]='\0';
  #endif
