--- dbus/dbus-sysdeps-util-unix.c.orig	2015-11-23 21:53:42 UTC
+++ dbus/dbus-sysdeps-util-unix.c
@@ -41,6 +41,7 @@
 #include <stdio.h>
 #include <errno.h>
 #include <fcntl.h>
+#include <syslog.h>
 #include <sys/stat.h>
 #ifdef HAVE_SYS_RESOURCE_H
 #include <sys/resource.h>
