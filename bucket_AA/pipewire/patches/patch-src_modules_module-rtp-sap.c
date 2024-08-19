--- src/modules/module-rtp-sap.c.orig	2024-07-31 10:02:24 UTC
+++ src/modules/module-rtp-sap.c
@@ -33,6 +33,10 @@
 #define SO_PASSCRED LOCAL_CREDS_PERSISTENT
 #endif
 
+#if defined(__DragonFly__)
+#define ifr_ifindex ifr_index
+#endif
+
 /** \page page_module_rtp_sap SAP Announce and create RTP streams
  *
  * The `rtp-sap` module announces RTP streams that match the rules with the
