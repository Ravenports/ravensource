--- source/Host/posix/DomainSocket.cpp.orig	2024-12-17 11:04:04 UTC
+++ source/Host/posix/DomainSocket.cpp
@@ -49,6 +49,7 @@ static bool SetSockAddr(llvm::StringRef
         offsetof(struct sockaddr_un, sun_path) + name_offset + name.size();
 
 #if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__) ||       \
+    defined(__DragonFly__) ||\
     defined(__OpenBSD__)
   saddr_un->sun_len = saddr_un_len;
 #endif
