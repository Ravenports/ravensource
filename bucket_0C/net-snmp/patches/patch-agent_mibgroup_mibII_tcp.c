--- agent/mibgroup/mibII/tcp.c.orig	2025-12-23 16:54:18 UTC
+++ agent/mibgroup/mibII/tcp.c
@@ -8,6 +8,14 @@
 #include <net-snmp/net-snmp-features.h>
 #include "mibII_common.h"
 
+#include <sys/param.h>
+
+#if defined(__MidnightBSD__) || (defined(__FreeBSD_version) && __FreeBSD_version > 1400066)
+#define IPFRAGTTL	60	/* time to live for frags, slowhz */
+#define PR_SLOWHZ	2	/* 2 slow timeouts per second */
+#define PR_FASTHZ	5	/* 5 fast timeouts per second */
+#endif
+
 #ifdef HAVE_STDLIB_H
 #include <stdlib.h>
 #endif
@@ -45,11 +53,13 @@
 #define MSEC_2_TICKS(m) max(1, (uint32_t)((hz == 1000) ? \
 	(m) : ((uint64_t)(m) * (uint64_t)hz)/(uint64_t)1000)) 
 #endif
+/* Force VNET_DECLARE to behave like a standard extern for userland */
+#ifndef VNET_DECLARE
+#define VNET_DECLARE(t, n) extern t n
+#endif
 #include <netinet/tcp_timer.h>
-#if __FreeBSD_version >= 1500048
 #undef _KERNEL
 #endif
-#endif
 #ifdef HAVE_NETINET_TCP_VAR_H
 #ifdef openbsd7
 #define _KERNEL /* OpenBSD 7.3 */
