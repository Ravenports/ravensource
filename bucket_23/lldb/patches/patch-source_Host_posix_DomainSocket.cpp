--- source/Host/posix/DomainSocket.cpp.orig	2025-04-29 23:05:17 UTC
+++ source/Host/posix/DomainSocket.cpp
@@ -43,6 +43,7 @@ static bool SetSockAddr(llvm::StringRef
         offsetof(struct sockaddr_un, sun_path) + name_offset + name.size();
 
 #if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__) ||       \
+    defined(__DragonFly__) ||\
     defined(__OpenBSD__)
   saddr_un->sun_len = saddr_un_len;
 #endif
