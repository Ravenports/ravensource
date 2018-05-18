--- Source/WebCore/platform/network/soup/SoupNetworkSession.h.orig	2018-05-07 08:56:05 UTC
+++ Source/WebCore/platform/network/soup/SoupNetworkSession.h
@@ -43,6 +43,7 @@ namespace WebCore {
 
 class CertificateInfo;
 class ResourceError;
+class URL;
 struct SoupNetworkProxySettings;
 
 class SoupNetworkSession {
