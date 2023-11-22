--- port/cpl_xml_validate.cpp.orig	2023-11-09 09:51:02 UTC
+++ port/cpl_xml_validate.cpp
@@ -914,7 +914,7 @@ static void CPLLibXMLWarningErrorCallbac
 
     if (strstr(pszStr, "since this namespace was already imported") == nullptr)
     {
-        xmlErrorPtr pErrorPtr = xmlGetLastError();
+        const xmlError *pErrorPtr = xmlGetLastError();
         const char *pszFilename = static_cast<char *>(ctx);
         char *pszStrDup = CPLStrdup(pszStr);
         int nLen = static_cast<int>(strlen(pszStrDup));
