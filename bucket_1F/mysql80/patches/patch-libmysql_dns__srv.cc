--- libmysql/dns_srv.cc.orig	2022-12-16 15:34:44 UTC
+++ libmysql/dns_srv.cc
@@ -31,7 +31,7 @@
 
 #ifdef HAVE_UNIX_DNS_SRV
 
-#ifdef __FreeBSD__
+#if defined __FreeBSD__ || defined __DragonFly__ || defined __NetBSD__
 #include <netinet/in.h>
 #endif
 #include <netdb.h>
