--- Source/WebCore/platform/network/soup/SoupNetworkSession.h.orig	2018-06-11 09:14:02 UTC
+++ Source/WebCore/platform/network/soup/SoupNetworkSession.h
@@ -44,6 +44,7 @@ namespace WebCore {
 
 class CertificateInfo;
 class ResourceError;
+class URL;
 struct SoupNetworkProxySettings;
 
 class SoupNetworkSession {
