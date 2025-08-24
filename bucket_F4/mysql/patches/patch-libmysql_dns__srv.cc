--- libmysql/dns_srv.cc.orig	2025-07-09 08:56:06 UTC
+++ libmysql/dns_srv.cc
@@ -32,7 +32,7 @@
 
 #ifdef HAVE_UNIX_DNS_SRV
 
-#ifdef __FreeBSD__
+#if defined __FreeBSD__ || defined __DragonFly__ || defined __NetBSD__ || defined __MidnightBSD__
 #include <netinet/in.h>
 #endif
 #include <netdb.h>
