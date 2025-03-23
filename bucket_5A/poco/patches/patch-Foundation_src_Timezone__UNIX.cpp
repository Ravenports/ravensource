--- Foundation/src/Timezone_UNIX.cpp.orig	2025-02-12 17:01:49 UTC
+++ Foundation/src/Timezone_UNIX.cpp
@@ -33,7 +33,7 @@ public:
 	{
 		std::lock_guard<std::mutex> lock(_mutex);
 
-	#if defined(__APPLE__)  || defined(__FreeBSD__) || defined (__OpenBSD__) || POCO_OS == POCO_OS_ANDROID // no timezone global var
+	#if defined(__APPLE__)  || defined(__FreeBSD__) || defined (__OpenBSD__) || defined(__DragonFly__) || POCO_OS == POCO_OS_ANDROID // no timezone global var
 		std::time_t now = std::time(NULL);
 		struct std::tm t;
 		gmtime_r(&now, &t);
@@ -86,7 +86,7 @@ int Timezone::dst(const Poco::Timestamp&
 	{
 #if defined(__CYGWIN__)
 		return local.__TM_GMTOFF - utcOffset();
-#elif defined(_BSD_SOURCE) || defined(__APPLE__)  || defined(__FreeBSD__) || defined (__OpenBSD__) || POCO_OS == POCO_OS_LINUX || POCO_OS == POCO_OS_ANDROID
+#elif defined(_BSD_SOURCE) || defined(__APPLE__)  || defined(__FreeBSD__) || defined (__OpenBSD__) || defined(__DragonFly__) || POCO_OS == POCO_OS_LINUX || POCO_OS == POCO_OS_ANDROID
 		return local.tm_gmtoff - utcOffset();
 #else
 		return 3600;
