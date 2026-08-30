--- ipmi-oem/ipmi-oem.h.orig	2026-08-12 22:14:51 UTC
+++ ipmi-oem/ipmi-oem.h
@@ -20,6 +20,9 @@
 #define IPMI_OEM_H
 
 #include <freeipmi/freeipmi.h>
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#include <sys/limits.h>
+#endif
 
 #include "tool-cmdline-common.h"
 #include "pstdout.h"
