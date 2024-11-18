--- src/process/sysdep_DRAGONFLY.c.orig	2024-10-11 11:02:44 UTC
+++ src/process/sysdep_DRAGONFLY.c
@@ -74,6 +74,7 @@
 #endif
 
 #include "monit.h"
+#include "system/Time.h"
 #include "ProcessTree.h"
 #include "process_sysdep.h"
 
@@ -141,7 +142,8 @@ bool init_systeminfo_sysdep(void) {
  * @return treesize > 0 if succeeded otherwise 0.
  */
 int init_processtree_sysdep(ProcessTree_T **reference, ProcessEngine_Flags pflags) {
-        kvm_t *kvm_handle = kvm_open(NULL, _PATH_DEVNULL, NULL, O_RDONLY, prog);
+	char errbuf[_POSIX2_LINE_MAX];
+        kvm_t *kvm_handle = kvm_open(NULL, _PATH_DEVNULL, NULL, O_RDONLY, errbuf);
         if (! kvm_handle) {
                 Log_error("system statistic error -- cannot initialize kvm interface\n");
                 return 0;
