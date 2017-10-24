--- jam.h.orig	2014-08-07 18:24:14 UTC
+++ jam.h
@@ -258,7 +258,7 @@
 # define OSMINOR "OS=CYGWIN"
 # define OS_CYGWIN
 # endif
-# ifdef __FreeBSD__
+# if defined __FreeBSD__ || defined __DragonFly__
 # define OSMINOR "OS=FREEBSD"
 # define OS_FREEBSD
 # endif
