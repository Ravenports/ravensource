--- include/lldb/Host/HostInfo.h.orig	2026-11-02 10:45:15 UTC
+++ include/lldb/Host/HostInfo.h
@@ -46,6 +46,9 @@
 #elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
 #include "lldb/Host/freebsd/HostInfoFreeBSD.h"
 #define HOST_INFO_TYPE HostInfoFreeBSD
+#elif defined(__DragonFly__)
+#include "lldb/Host/dragonfly/HostInfoDragonFly.h"
+#define HOST_INFO_TYPE HostInfoDragonFly
 #elif defined(__NetBSD__)
 #include "lldb/Host/netbsd/HostInfoNetBSD.h"
 #define HOST_INFO_TYPE HostInfoNetBSD
