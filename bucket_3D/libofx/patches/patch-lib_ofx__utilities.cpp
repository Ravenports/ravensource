--- lib/ofx_utilities.cpp.orig	2021-01-25 21:10:19 UTC
+++ lib/ofx_utilities.cpp
@@ -138,6 +138,11 @@ time_t ofxdate_to_time_t(const string of
   char time_zone_specified = false;
   string ofxdate_whole;
   time_t temptime;
+  int daylight = 0;
+
+  tzset();
+  if(tzname[1][0] != ' ')
+    daylight = 1;
 
   std::time(&temptime);
   local_offset = difftime(mktime(localtime(&temptime)), mktime(gmtime(&temptime)));
