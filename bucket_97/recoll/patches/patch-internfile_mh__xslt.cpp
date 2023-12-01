--- internfile/mh_xslt.cpp.orig	2023-08-04 06:18:39 UTC
+++ internfile/mh_xslt.cpp
@@ -66,7 +66,7 @@ public:
     xmlDocPtr getDoc() {
         int ret;
         if ((ret = xmlParseChunk(ctxt, nullptr, 0, 1))) {
-            xmlError *error = xmlGetLastError();
+            const xmlError *error = xmlGetLastError();
             LOGERR("FileScanXML: final xmlParseChunk failed with error " <<
                    ret << " error: " <<
                    (error ? error->message :
@@ -95,7 +95,7 @@ public:
         }            
         int ret;
         if ((ret = xmlParseChunk(ctxt, buf, cnt, 0))) {
-            xmlError *error = xmlGetLastError();
+            const xmlError *error = xmlGetLastError();
             LOGERR("FileScanXML: xmlParseChunk failed with error " <<
                    ret << " for [" << buf << "] error " <<
                    (error ? error->message :
