--- lib/xml.c.orig	2020-05-29 20:22:11 UTC
+++ lib/xml.c
@@ -14,9 +14,11 @@
 
 #include <config.h>
 
+#if !(defined(__DragonFly__) || defined(__FreeBSD__))
 #ifndef	_XOPEN_SOURCE
 #   define _XOPEN_SOURCE 500
 #endif
+#endif
 
 #if defined(__linux__)
 #   ifndef _GNU_SOURCE
@@ -40,7 +42,7 @@
 #endif
 #include <sys/stat.h>
 #include <sys/types.h>
-#if defined(__linux__)
+#if defined(__linux__) || defined(__DragonFly__) || defined(__FreeBSD__)
 #include <dlfcn.h>
 #elif defined(__APPLE__)
 #define _DARWIN_C_SOURCE
@@ -2137,7 +2139,7 @@ default_udunits2_xml_path()
     const char* path;
     char const* soname = 0;
 
-#if defined(__APPLE__) || defined(__linux__)
+#if defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__)
     #define END_BIT "/share/udunits/udunits2.xml"
     #define SEP '/'
     Dl_info info;
