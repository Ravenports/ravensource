--- include/greet.h.orig	2024-04-05 00:04:33 UTC
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
