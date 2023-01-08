--- agent/mibgroup/ip-mib/data_access/scalars_sysctl.c.orig	2022-07-13 21:14:14 UTC
+++ agent/mibgroup/ip-mib/data_access/scalars_sysctl.c
@@ -9,6 +9,7 @@
 #include <net-snmp/agent/net-snmp-agent-includes.h>
 #include <net-snmp/data_access/ip_scalars.h>
 
+#include <sys/param.h>
 #include <sys/types.h>
 #include <sys/protosw.h>
 #include <sys/sysctl.h>
@@ -17,6 +18,12 @@
 #include <errno.h>
 #include <stdlib.h>
 
+#if defined(__FreeBSD_version) && __FreeBSD_version > 1400066
+#define IPFRAGTTL	60	/* time to live for frags, slowhz */
+#define PR_SLOWHZ	2	/* 2 slow timeouts per second */
+#define PR_FASTHZ	5	/* 5 fast timeouts per second */
+#endif
+
 /* XXX: the values passed to netsnmp_arch_ip_scalars(..) may or may not be
  * portable to the other BSDs -- it seems to be portable back to FreeBSD 4.x
  * (Darwin 10.8.0) at least.
