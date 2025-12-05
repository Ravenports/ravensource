--- source/Host/posix/DomainSocket.cpp.orig	2025-12-01 12:58:50 UTC
+++ source/Host/posix/DomainSocket.cpp
@@ -48,6 +48,7 @@ static bool SetSockAddr(llvm::StringRef
         offsetof(struct sockaddr_un, sun_path) + name_offset + name.size();
 
 #if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__) ||       \
+    defined(__DragonFly__) ||\
     defined(__OpenBSD__)
   saddr_un->sun_len = saddr_un_len;
 #endif
