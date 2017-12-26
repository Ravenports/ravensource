--- src/dialects/bsd/procinfo.h.orig	2013-10-07 12:11:29 UTC
+++ src/dialects/bsd/procinfo.h
@@ -1,7 +1,11 @@
 #ifdef HAVE_PROCESS_SYSCTL
 #include <sys/param.h>
 #include <sys/sysctl.h>
+# ifdef __DragonFly__
+#include <sys/user.h>
+# else
 #include <sys/proc.h>
+# endif
 #include <sys/stat.h>
 #endif
 
