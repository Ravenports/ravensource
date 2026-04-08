--- avahi-core/iface-pfroute.c.orig	2020-02-17 04:46:57 UTC
+++ avahi-core/iface-pfroute.c
@@ -519,7 +519,7 @@ void avahi_interface_monitor_sync(AvahiI
             avahi_log_error("malloc failed in avahi_interface_monitor_sync");
             goto end;
     }
-    lifc.lifc_family = NULL;
+    lifc.lifc_family = AF_UNSPEC;
     lifc.lifc_flags = 0;
     if(ioctl(sockfd, SIOCGLIFCONF, &lifc) < 0) {
         avahi_log_error(__FILE__": ioctl(SIOCGLIFCONF): %s", strerror(errno));
