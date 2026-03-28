--- Foundation/src/Timezone_UNIX.cpp.orig	2026-03-24 10:38:30 UTC
+++ Foundation/src/Timezone_UNIX.cpp
@@ -77,7 +77,7 @@ private:
 
 	static int computeTimeZone()
 	{
-#if defined(__APPLE__)  || defined(__FreeBSD__) || defined (__OpenBSD__) || POCO_OS == POCO_OS_ANDROID // no timezone global var
+#if defined(__APPLE__)  || defined(__FreeBSD__) || defined (__OpenBSD__) || defined (__DragonFly__) || POCO_OS == POCO_OS_ANDROID // no timezone global var
 		// Get offset from a date when DST is not active.
 		// Check both January and July - one of them won't have DST.
 		struct std::tm jan = {};
@@ -140,7 +140,7 @@ int Timezone::dst(const Poco::Timestamp&
 	{
 #if defined(__CYGWIN__)
 		return local.__TM_GMTOFF - utcOffset();
-#elif defined(_BSD_SOURCE) || defined(__APPLE__)  || defined(__FreeBSD__) || defined (__OpenBSD__) || POCO_OS == POCO_OS_LINUX || POCO_OS == POCO_OS_ANDROID
+#elif defined(_BSD_SOURCE) || defined(__APPLE__)  || defined(__FreeBSD__) || defined (__OpenBSD__) || defined(__DragonFly__) || POCO_OS == POCO_OS_LINUX || POCO_OS == POCO_OS_ANDROID
 		return local.tm_gmtoff - utcOffset();
 #else
 		return 3600;
