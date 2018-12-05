--- src/network/kernel/qnetworkinterface_unix.cpp.orig	2018-11-25 12:51:11 UTC
+++ src/network/kernel/qnetworkinterface_unix.cpp
@@ -463,8 +463,10 @@ static QNetworkInterface::InterfaceType
         case IFM_ETHER:
             return QNetworkInterface::Ethernet;
 
+#ifdef IFM_FDDI
         case IFM_FDDI:
             return QNetworkInterface::Fddi;
+#endif
 
         case IFM_IEEE80211:
             return QNetworkInterface::Ieee80211;
