--- Utilities/cmcurl/lib/curl_setup.h.orig	2023-07-18 17:52:42 UTC
+++ Utilities/cmcurl/lib/curl_setup.h
@@ -24,6 +24,7 @@
  *
  ***************************************************************************/
 
+#define __BSD_VISIBLE 1
 #if defined(BUILDING_LIBCURL) && !defined(CURL_NO_OLDIES)
 #define CURL_NO_OLDIES
 #endif
