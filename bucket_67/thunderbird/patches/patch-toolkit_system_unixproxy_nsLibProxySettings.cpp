--- toolkit/system/unixproxy/nsLibProxySettings.cpp.orig	2026-05-23 13:30:56 UTC
+++ toolkit/system/unixproxy/nsLibProxySettings.cpp
@@ -111,6 +111,12 @@ nsUnixSystemProxySettings::GetSystemWPAD
   return NS_OK;
 }
 
+NS_IMETHODIMP
+nsUnixSystemProxySettings::GetSystemProxyDirect(bool* aResult) {
+  *aResult = false;
+  return NS_OK;
+}
+
 NS_IMPL_COMPONENT_FACTORY(nsUnixSystemProxySettings) {
   return do_AddRef(new nsUnixSystemProxySettings()).downcast<nsISupports>();
 }
