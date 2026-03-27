--- libdnet-stripped/src/intf.c.orig	2026-03-19 17:39:59 UTC
+++ libdnet-stripped/src/intf.c
@@ -179,7 +179,11 @@ intf_open(void)
 		if ((intf->fd6 = socket(AF_INET6, SOCK_DGRAM, 0)) < 0) {
 			if (1
 #  ifdef EPROTONOSUPPORT
+#    if defined(__FreeBSD__) || defined(__DragonFly__)
+              && (errno != EPROTONOSUPPORT && errno != EAFNOSUPPORT)
+#    else
 					&& errno != EPROTONOSUPPORT
+#    endif
 #endif
 #  ifdef EAFNOSUPPORT
 					&& errno != EAFNOSUPPORT
