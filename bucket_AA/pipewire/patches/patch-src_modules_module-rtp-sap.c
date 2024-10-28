--- src/modules/module-rtp-sap.c.orig	2024-10-23 07:44:10 UTC
+++ src/modules/module-rtp-sap.c
@@ -32,6 +32,14 @@
 #define SO_PASSCRED LOCAL_CREDS_PERSISTENT
 #endif
 
+#if defined(__DragonFly__)
+#define ifr_ifindex ifr_index
+#endif
+
+#if defined(__MidnightBSD__)
+#include <sys/endian.h>
+#endif
+
 /** \page page_module_rtp_sap SAP Announce and create RTP streams
  *
  * The `rtp-sap` module announces RTP streams that match the rules with the
@@ -382,11 +390,13 @@ static int make_unix_socket(const char *
 		return -1;
 	}
 
+#if !defined(__MidnightBSD__)
 	int val = 1;
 	if (setsockopt(fd, SOL_SOCKET, SO_PASSCRED, &val, sizeof(val)) < 0) {
 		pw_log_warn("Failed to bind PTP management socket");
 		return -1;
 	}
+#endif
 
 	spa_zero(addr);
 	addr.sun_family = AF_UNIX;
