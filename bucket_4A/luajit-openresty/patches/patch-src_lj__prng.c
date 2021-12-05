--- src/lj_prng.c.orig	2021-05-06 06:13:24 UTC
+++ src/lj_prng.c
@@ -109,6 +109,7 @@ static PRGR libfunc_rgr;
 #include <sys/syscall.h>
 #else
 
+# ifndef LJ_TARGET_HAS_GETENTROPY
 #if LJ_TARGET_OSX
 #include <Availability.h>
 #if __MAC_OS_X_VERSION_MIN_REQUIRED >= 101200 || \
@@ -118,6 +119,7 @@ static PRGR libfunc_rgr;
 #elif LJ_TARGET_BSD || LJ_TARGET_SOLARIS || LJ_TARGET_CYGWIN
 #define LJ_TARGET_HAS_GETENTROPY	1
 #endif
+# endif
 
 #if LJ_TARGET_HAS_GETENTROPY
 extern int getentropy(void *buf, size_t len);
