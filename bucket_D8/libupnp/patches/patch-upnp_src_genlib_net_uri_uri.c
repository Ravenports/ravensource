--- upnp/src/genlib/net/uri/uri.c.orig	2026-04-22 19:28:40 UTC
+++ upnp/src/genlib/net/uri/uri.c
@@ -45,10 +45,12 @@
 #include <assert.h>
 
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
