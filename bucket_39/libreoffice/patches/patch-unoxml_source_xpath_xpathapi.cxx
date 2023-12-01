--- unoxml/source/xpath/xpathapi.cxx.orig	2023-09-22 19:07:01 UTC
+++ unoxml/source/xpath/xpathapi.cxx
@@ -217,7 +217,7 @@ namespace XPath
         return selectSingleNode(contextNode, expr);
     }
 
-    static OUString make_error_message(xmlErrorPtr pError)
+    static OUString make_error_message(const _xmlError * pError)
     {
         OUStringBuffer buf;
         if (pError) {
@@ -259,7 +259,7 @@ namespace XPath
             SAL_WARN("unoxml", "libxml2 error: " << str);
         }
 
-        static void structured_error_func(void *, xmlErrorPtr error)
+        static void structured_error_func(void *, const _xmlError * error)
         {
             SAL_WARN("unoxml", "libxml2 error: " << make_error_message(error));
         }
