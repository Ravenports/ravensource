--- cmake/config.h.cmake.orig	2025-02-27 16:29:06 UTC
+++ cmake/config.h.cmake
@@ -24,7 +24,8 @@
 # define __EXTENSIONS__
 # define _POSIX_PTHREAD_SEMANTICS
 # define _REENTRANT
-# define _XOPEN_SOURCE 500
+# define _XOPEN_SOURCE 1
+# define _XOPEN_SOURCE_EXTENDED 1
 #endif
 
 #cmakedefine DBUS_DATADIR  "@DBUS_DATADIR@"
