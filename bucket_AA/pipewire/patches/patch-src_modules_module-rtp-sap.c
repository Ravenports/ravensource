--- src/modules/module-rtp-sap.c.orig	2024-09-27 10:02:20 UTC
+++ src/modules/module-rtp-sap.c
@@ -32,6 +32,10 @@
 #define SO_PASSCRED LOCAL_CREDS_PERSISTENT
 #endif
 
+#if defined(__DragonFly__)
+#define ifr_ifindex ifr_index
+#endif
+
 /** \page page_module_rtp_sap SAP Announce and create RTP streams
  *
  * The `rtp-sap` module announces RTP streams that match the rules with the
