--- gcore/gdaljp2metadatagenerator.cpp.orig	2023-11-09 09:51:02 UTC
+++ gcore/gdaljp2metadatagenerator.cpp
@@ -357,7 +357,12 @@ static CPLString GDALGMLJP2EvalExpr(cons
 /************************************************************************/
 
 static void GDALGMLJP2XPathErrorHandler(void * /* userData */,
-                                        xmlErrorPtr error)
+#if LIBXML_VERSION >= 21200
+                                        const xmlError *error
+#else
+                                        xmlErrorPtr error
+#endif
+)
 {
     if (error->domain == XML_FROM_XPATH && error->str1 != nullptr &&
         error->int1 < static_cast<int>(strlen(error->str1)))
