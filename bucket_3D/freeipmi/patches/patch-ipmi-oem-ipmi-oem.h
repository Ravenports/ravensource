--- ipmi-oem/ipmi-oem.h.orig	2023-06-05 22:58:26 UTC
+++ ipmi-oem/ipmi-oem.h
@@ -20,6 +20,9 @@
 #define IPMI_OEM_H
 
 #include <freeipmi/freeipmi.h>
+#if !defined(__linux__)
+#include <sys/limits.h>
+#endif
 
 #include "tool-cmdline-common.h"
 #include "pstdout.h"
