--- lib/xml.c.orig	2020-11-20 20:55:28 UTC
+++ lib/xml.c
@@ -38,7 +38,8 @@
 #endif
 #include <sys/stat.h>
 #include <sys/types.h>
-#if defined(__linux__)
+#if defined(__linux__) || defined(__DragonFly__) || defined(__FreeBSD__)
+#define __BSD_VISIBLE 1
 #include <dlfcn.h>
 #elif defined(__APPLE__)
 #define _DARWIN_C_SOURCE
@@ -2135,7 +2136,7 @@ default_udunits2_xml_path()
     static char absXmlPathname[PATH_MAX];
 
     if (absXmlPathname[0] == 0) {
-#       if defined(__APPLE__) || defined(__linux__)
+#       if defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__)
             Dl_info     info;
             const char  sep = '/'; ///< Pathname component separator
             char        buf[PATH_MAX];
