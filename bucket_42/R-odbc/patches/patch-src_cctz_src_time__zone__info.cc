--- src/cctz/src/time_zone_info.cc.orig	2018-01-10 15:12:31 UTC
+++ src/cctz/src/time_zone_info.cc
@@ -54,7 +54,7 @@ char* errmsg(int errnum, char* buf, size
 #if defined(_WIN32) || defined(_WIN64)
   strerror_s(buf, buflen, errnum);
   return buf;
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
   strerror_r(errnum, buf, buflen);
   return buf;
 #elif (_POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600) && !_GNU_SOURCE
