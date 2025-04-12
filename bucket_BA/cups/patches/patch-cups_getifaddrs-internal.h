--- cups/getifaddrs-internal.h.orig	2025-04-08 10:47:14 UTC
+++ cups/getifaddrs-internal.h
@@ -31,6 +31,14 @@
 #    define CUPS_SOCAST
 #  endif /* _WIN32 */
 
+#  if defined(__DragonFly__) || defined(__FreeBSD__)
+#    include <netinet/in.h>
+#  endif
+
+#  if !defined(_WIN32) && !defined(HAVE_GETIFADDRS)
+#    include <cups/versioning.h>
+#  endif
+
 #  if defined(__APPLE__) && !defined(_SOCKLEN_T)
 /*
  * macOS 10.2.x does not define socklen_t, and in fact uses an int instead of
