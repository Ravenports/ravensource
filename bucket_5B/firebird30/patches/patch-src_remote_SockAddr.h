--- src/remote/SockAddr.h.orig	2017-03-21 09:11:36 UTC
+++ src/remote/SockAddr.h
@@ -90,6 +90,7 @@ public:
 
 #define AF_INET6_POSIX		10
 #define AF_INET6_WINDOWS	23
+#define AF_INET6_BSD		28
 
 inline void SockAddr::checkAndFixFamily()
 {
@@ -97,6 +98,8 @@ inline void SockAddr::checkAndFixFamily(
 	if (data.sock.sa_family == AF_INET6_WINDOWS)
 #elif AF_INET6 == AF_INET6_WINDOWS
 	if (data.sock.sa_family == AF_INET6_POSIX)
+#elif AF_INET6 == AF_INET6_BSD
+	if (data.sock.sa_family == AF_INET6_BSD)
 #else
 #error Unknown value of AF_INET6 !
 #endif
