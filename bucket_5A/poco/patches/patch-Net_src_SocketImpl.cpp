--- Net/src/SocketImpl.cpp.orig	2026-03-24 10:38:31 UTC
+++ Net/src/SocketImpl.cpp
@@ -1274,7 +1274,7 @@ void SocketImpl::initSocket(int af, int
 	if (_sockfd == POCO_INVALID_SOCKET)
 		error();
 
-#if defined(__MACH__) && defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__MACH__) && defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
 	// SIGPIPE sends a signal that if unhandled (which is the default)
 	// will crash the process. This only happens on UNIX, and not Linux.
 	//
