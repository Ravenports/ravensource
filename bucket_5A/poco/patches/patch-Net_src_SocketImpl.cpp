--- Net/src/SocketImpl.cpp.orig	2025-02-12 17:01:50 UTC
+++ Net/src/SocketImpl.cpp
@@ -1273,7 +1273,7 @@ void SocketImpl::initSocket(int af, int
 	if (_sockfd == POCO_INVALID_SOCKET)
 		error();
 
-#if defined(__MACH__) && defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__MACH__) && defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
 	// SIGPIPE sends a signal that if unhandled (which is the default)
 	// will crash the process. This only happens on UNIX, and not Linux.
 	//
