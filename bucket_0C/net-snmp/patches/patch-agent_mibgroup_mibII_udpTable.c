--- agent/mibgroup/mibII/udpTable.c.orig	2022-07-13 21:14:14 UTC
+++ agent/mibgroup/mibII/udpTable.c
@@ -94,10 +94,10 @@ struct netsnmp_udpEntry_s {
 #define INP_NEXT_SYMBOL		inp_queue.cqe_next	/* or set via <net-snmp/system/openbsd.h> */
 #endif
 
-#if defined(freebsd4) || defined(darwin) || defined(osf5)
+#if defined(freebsd4) || defined(darwin) || defined(osf5) || defined(__MidnightBSD__)
 typedef struct netsnmp_inpcb_s netsnmp_inpcb;
 struct netsnmp_inpcb_s {
-#if __FreeBSD_version >= 1200026
+#if defined(__MidnightBSD__) || (__FreeBSD_version >= 1200026)
     struct xinpcb   pcb;
 #else
     struct inpcb    pcb;
