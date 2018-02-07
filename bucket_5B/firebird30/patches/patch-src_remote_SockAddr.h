--- src/remote/SockAddr.h.orig	2018-02-02 11:00:36 UTC
+++ src/remote/SockAddr.h
@@ -90,6 +90,7 @@ public:
 
 #define AF_INET6_POSIX		10
 #define AF_INET6_WINDOWS	23
+#define AF_INET6_BSD		28
 #define AF_INET6_DARWIN		30
 
 inline void SockAddr::checkAndFixFamily()
@@ -98,6 +99,8 @@ inline void SockAddr::checkAndFixFamily(
 	if (data.sock.sa_family == AF_INET6_WINDOWS)
 #elif AF_INET6 == AF_INET6_WINDOWS
 	if (data.sock.sa_family == AF_INET6_POSIX)
+#elif AF_INET6 == AF_INET6_BSD
+	if (data.sock.sa_family == AF_INET6_BSD)
 #elif AF_INET6 == AF_INET6_DARWIN
 	if (data.sock.sa_family == AF_INET6_DARWIN)
 #else
