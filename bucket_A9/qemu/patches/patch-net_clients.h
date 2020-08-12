--- net/clients.h.orig	2020-08-11 19:17:15 UTC
+++ net/clients.h
@@ -61,6 +61,12 @@ int net_init_netmap(const Netdev *netdev
 int net_init_vhost_user(const Netdev *netdev, const char *name,
                         NetClientState *peer, Error **errp);
 
+#ifdef CONFIG_PCAP
+int net_init_pcap(const Netdev *netdev, const char *name,
+                    NetClientState *peer, Error **errp);
+#endif
+
+
 int net_init_vhost_vdpa(const Netdev *netdev, const char *name,
                         NetClientState *peer, Error **errp);
 #endif /* QEMU_NET_CLIENTS_H */
