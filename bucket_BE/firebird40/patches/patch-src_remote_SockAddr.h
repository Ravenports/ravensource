--- src/remote/SockAddr.h.orig	2021-05-29 15:05:06 UTC
+++ src/remote/SockAddr.h
@@ -106,11 +106,13 @@ public:
 
 #define AF_INET6_POSIX		10
 #define AF_INET6_WINDOWS	23
+#define AF_INET6_BSD		28
 #define AF_INET6_DARWIN		30
 
 #if AF_INET6 == AF_INET6_POSIX
 #elif AF_INET6 == AF_INET6_WINDOWS
 #elif AF_INET6 == AF_INET6_DARWIN
+#elif AF_INET6 == AF_INET6_BSD
 #else
 #error Unknown value of AF_INET6 !
 #endif
@@ -126,6 +128,7 @@ inline void SockAddr::checkAndFixFamily(
 	case AF_INET6_POSIX:
 	case AF_INET6_WINDOWS:
 	case AF_INET6_DARWIN:
+	case AF_INET6_BSD:
 		data.sock.sa_family = AF_INET6;
 		fb_assert(len == sizeof(sockaddr_in6));
 		break;
