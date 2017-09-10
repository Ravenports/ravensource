--- src/FS.cpp.orig	2016-02-24 22:18:11 UTC
+++ src/FS.cpp
@@ -41,9 +41,7 @@
 #include <util.h>
 #include <i18n.h>
 
-#if defined SOLARIS || defined NETBSD || defined FREEBSD
 #include <limits.h>
-#endif
 
 #if defined __APPLE__
 #include <sys/syslimits.h>
