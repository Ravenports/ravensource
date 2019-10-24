--- cups/getifaddrs-internal.h.orig	2019-08-23 15:19:38 UTC
+++ cups/getifaddrs-internal.h
@@ -28,6 +28,10 @@
 #    define CUPS_SOCAST
 #  endif /* _WIN32 */
 
+#  if defined(__DragonFly__)
+#    include <netinet/in.h>
+#  endif
+
 #  if defined(__APPLE__) && !defined(_SOCKLEN_T)
 /*
  * macOS 10.2.x does not define socklen_t, and in fact uses an int instead of
