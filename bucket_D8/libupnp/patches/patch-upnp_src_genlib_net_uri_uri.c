--- upnp/src/genlib/net/uri/uri.c.orig	2024-02-19 19:47:15 UTC
+++ upnp/src/genlib/net/uri/uri.c
@@ -37,10 +37,12 @@
  */
 
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
