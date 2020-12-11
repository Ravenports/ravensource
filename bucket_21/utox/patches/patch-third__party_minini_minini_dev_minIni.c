--- third_party/minini/minini/dev/minIni.c.orig	2020-12-11 21:24:06 UTC
+++ third_party/minini/minini/dev/minIni.c
@@ -71,7 +71,7 @@
   #pragma warning(disable: 4996)	/* for Microsoft Visual C/C++ */
 #endif
 #if !defined strnicmp && !defined PORTABLE_STRNICMP
-  #if defined __LINUX__ || defined __FreeBSD__ || defined __OpenBSD__ || defined __APPLE__
+  #if defined __LINUX__ || defined __FreeBSD__ || defined __OpenBSD__ || defined __APPLE__ || defined __DragonFly__ || defined __NetBSD_
     #define strnicmp  strncasecmp
   #endif
 #endif
@@ -80,7 +80,7 @@
 #endif
 
 #if !defined INI_LINETERM
-  #if defined __LINUX__ || defined __FreeBSD__ || defined __OpenBSD__ || defined __APPLE__
+  #if defined __LINUX__ || defined __FreeBSD__ || defined __OpenBSD__ || defined __APPLE__ || defined __DragonFly__ || defined __NetBSD__
     #define INI_LINETERM    __T("\n")
   #else
     #define INI_LINETERM    __T("\r\n")
