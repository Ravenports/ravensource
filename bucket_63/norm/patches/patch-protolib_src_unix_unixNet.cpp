--- protolib/src/unix/unixNet.cpp.orig	2021-03-05 19:41:33 UTC
+++ protolib/src/unix/unixNet.cpp
@@ -136,7 +136,7 @@ bool ProtoNet::GetInterfaceAddressList(c
     
     if (ProtoAddress::ETH == addressType)
     {
-#ifdef SIOCGIFHWADDR
+#if defined(SIOCGIFHWADDR) && !defined(__sun)
         // Probably Linux
         // Get hardware (MAC) address instead of IP address
         if (ioctl(socketFd, SIOCGIFHWADDR, &req) < 0)
@@ -625,7 +625,7 @@ static int GetInterfaceList(struct ifcon
 
     int ifNum = 32;  // first guess for max # of interfaces
 #ifdef SIOCGIFNUM  // Solaris has this, others might
-	if (ioctl(sock, SIOCGIFNUM, &ifNum) >= 0) ifNum++;
+	if (ioctl(sockFd, SIOCGIFNUM, &ifNum) >= 0) ifNum++;
 #endif // SIOCGIFNUM
     // We loop here until we get a fully successful SIOGIFCONF
     // This returns us a list of all interfaces
@@ -697,7 +697,7 @@ unsigned int ProtoNet::GetInterfaceIndex
 #ifdef HAVE_IPV6
     index = if_nametoindex(interfaceName);
 #else
-#ifdef SIOCGIFINDEX
+#if defined(SIOCGIFINDEX) && !defined(__sun)
     int sockFd = socket(PF_INET, SOCK_DGRAM, 0);
     if (sockFd < 0) 
     {
@@ -746,7 +746,7 @@ unsigned int ProtoNet::GetInterfaceName(
         return 0;
     }
 #else
-#ifdef SIOCGIFNAME
+#if defined(SIOCGIFNAME) && !defined(__sun)
     int sockFd = socket(PF_INET, SOCK_DGRAM, 0);
     if (sockFd < 0) 
     {
