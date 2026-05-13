--- Foundation/include/Poco/Types.h.orig	2026-04-16 18:15:35 UTC
+++ Foundation/include/Poco/Types.h
@@ -54,7 +54,7 @@ using UIntPtr = std::uintptr_t;
 		#if defined(__LP64__)
 			#define POCO_PTR_IS_64_BIT 1
 			#define POCO_LONG_IS_64_BIT 1
-			#if POCO_OS == POCO_OS_LINUX || POCO_OS == POCO_OS_FREE_BSD || POCO_OS == POCO_OS_ANDROID || POCO_OS == POCO_OS_AIX || POCO_OS == POCO_OS_QNX || POCO_OS == POCO_OS_SOLARIS || POCO_OS == POCO_OS_GNU_HURD
+			#if POCO_OS == POCO_OS_LINUX || POCO_OS == POCO_OS_FREE_BSD || POCO_OS == POCO_OS_ANDROID || POCO_OS == POCO_OS_AIX || POCO_OS == POCO_OS_QNX || POCO_OS == POCO_OS_SOLARIS || POCO_OS == POCO_OS_GNU_HURD || POCO_OS == POCO_OS_NET_BSD
 				#define POCO_INT64_IS_LONG 1
 			#endif
 		#endif
