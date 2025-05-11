--- libdnet-stripped/src/intf.c.orig	2025-03-31 19:30:47 UTC
+++ libdnet-stripped/src/intf.c
@@ -178,7 +178,11 @@ intf_open(void)
 #if defined(SIOCGLIFCONF) || defined(SIOCGIFNETMASK_IN6) || defined(SIOCGIFNETMASK6)
 		if ((intf->fd6 = socket(AF_INET6, SOCK_DGRAM, 0)) < 0) {
 #  ifdef EPROTONOSUPPORT
+#    if defined(__FreeBSD__) || defined(__DragonFly__)
+			if (errno != EPROTONOSUPPORT && errno != EAFNOSUPPORT)
+#    else
 			if (errno != EPROTONOSUPPORT)
+#    endif
 #endif
 				return (intf_close(intf));
 		}
