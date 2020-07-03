--- lib/hostcheck.h.orig	2020-06-25 09:31:43 UTC
+++ lib/hostcheck.h
@@ -23,6 +23,7 @@
  ***************************************************************************/
 
 #include <curl/curl.h>
+#include <netinet/in.h>
 
 #define CURL_HOST_NOMATCH 0
 #define CURL_HOST_MATCH   1
