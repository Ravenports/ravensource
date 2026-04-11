--- sio/DNSUtil.c.orig	2025-03-23 02:12:36 UTC
+++ sio/DNSUtil.c
@@ -7,16 +7,10 @@
 #define _CRT_SECURE_NO_WARNINGS 1
 #endif
 
-#ifndef HAVE_GETNAMEINFO
-#	ifndef STRNCPY
-#		define STRNCPY(a,b) strncpy(a, b, sizeof(a)); a[sizeof(a) - 1] = '\0'
-#		define Strncpy(a,b,s) strncpy(a, b, s); a[s - 1] = '\0' 
-#	endif
 
 #	if (((defined(MACOSX)) && (MACOSX < 10300)) || (defined(AIX) && (AIX < 430)) || (defined(DIGITAL_UNIX)) || (defined(SOLARIS)) || (defined(SCO)) || (defined(HPUX)))
 extern int getdomainname(char *name, getdomainname_size_t namelen);
 #	endif
-#endif
 
 
 
