--- include/greet.h.orig	2025-03-09 01:13:49 UTC
+++ include/greet.h
@@ -45,11 +45,7 @@ from The Open Group.
 # define GETPWNAM_ARGS /*unknown*/
 #endif
 
-#if defined(__FreeBSD__) || defined(__bsdi__)
-# define SETGRENT_TYPE int
-#else
 # define SETGRENT_TYPE void
-#endif
 
 struct dlfuncs {
     int (*_PingServer)(struct display *d, Display *alternateDpy);
