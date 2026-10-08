--- Utilities/cmcurl/lib/curl_setup.h.orig	2026-10-02 15:29:10 UTC
+++ Utilities/cmcurl/lib/curl_setup.h
@@ -24,6 +24,7 @@
  *
  ***************************************************************************/
 
+#define __BSD_VISIBLE 1
 #if defined(BUILDING_LIBCURL) && !defined(CURL_NO_OLDIES)
 #define CURL_NO_OLDIES
 #endif
