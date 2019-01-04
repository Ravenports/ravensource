--- src/vde_pcapplug.c.orig	2011-11-23 16:41:18 UTC
+++ src/vde_pcapplug.c
@@ -196,7 +196,7 @@ void pcap_callback(u_char *u, const stru
 void setup_fd(int fd)
 {
 /* FreeBSD settings */
-#if defined(VDE_FREEBSD)
+#if 0 // BIOC* not defined by port libpcap 
 	/*
 	 * Tell the kernel that the header is fully-formed when it gets it.
 	 * This is required in order to fake the src address.
