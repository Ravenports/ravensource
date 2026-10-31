--- upnp/src/genlib/net/uri/uri.c.orig	2026-10-29 20:17:58 UTC
+++ upnp/src/genlib/net/uri/uri.c
@@ -55,10 +55,12 @@
 #include <string.h>
 
 #ifdef __FreeBSD__
+# ifndef __MidnightBSD__
 	#include <osreldate.h>
 	#if __FreeBSD_version < 601103
 		#include <lwres/netdb.h>
 	#endif
+# endif
 #endif
 #ifdef _WIN32
 	#if defined(_MSC_VER) && _MSC_VER < 1900
