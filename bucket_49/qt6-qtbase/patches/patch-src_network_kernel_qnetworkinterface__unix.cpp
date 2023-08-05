--- src/network/kernel/qnetworkinterface_unix.cpp.orig	2023-07-06 10:02:03 UTC
+++ src/network/kernel/qnetworkinterface_unix.cpp
@@ -63,7 +63,7 @@ uint QNetworkInterfaceManager::interface
 {
 #ifndef QT_NO_IPV6IFNAME
     return ::if_nametoindex(name.toLatin1());
-#elif defined(SIOCGIFINDEX)
+#elif defined(SIOCGIFINDEX) && !defined(__sun__)
     struct ifreq req;
     int socket = qt_safe_socket(AF_INET, SOCK_STREAM, 0);
     if (socket < 0)
@@ -117,7 +117,7 @@ QString QNetworkInterfaceManager::interf
 
 static int getMtu(int socket, struct ifreq *req)
 {
-#ifdef SIOCGIFMTU
+#if defined(SIOCGIFMTU) && !defined(__sun__) 
     if (qt_safe_ioctl(socket, SIOCGIFMTU, req) == 0)
         return req->ifr_mtu;
 #endif
@@ -185,7 +185,7 @@ static QNetworkInterfacePrivate *findInt
     QNetworkInterfacePrivate *iface = nullptr;
     int ifindex = 0;
 
-#if !defined(QT_NO_IPV6IFNAME) || defined(SIOCGIFINDEX)
+#if !defined(QT_NO_IPV6IFNAME) || (defined(SIOCGIFINDEX) && !defined(__sun__))
     // Get the interface index
 #  ifdef SIOCGIFINDEX
     if (qt_safe_ioctl(socket, SIOCGIFINDEX, &req) >= 0)
