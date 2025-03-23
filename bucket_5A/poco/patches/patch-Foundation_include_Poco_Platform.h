--- Foundation/include/Poco/Platform.h.orig	2025-02-12 17:01:49 UTC
+++ Foundation/include/Poco/Platform.h
@@ -44,7 +44,7 @@
 #define POCO_OS_VMS           0x2001
 
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
 	#define POCO_OS_FAMILY_UNIX 1
 	#define POCO_OS_FAMILY_BSD 1
 	#define POCO_OS POCO_OS_FREE_BSD
