--- dao/GenericMMC.cc.orig	2018-05-15 13:30:52 UTC
+++ dao/GenericMMC.cc
@@ -2064,7 +2064,7 @@ CdRawToc *GenericMMC::getRawToc(int sess
     return NULL;
   }
 
-  dataLen = ((reqData[0] << 8) | reqData[1]) + 2;
+  dataLen = (dataLen + 1) & ~1;
   
   log_message(4, "Raw toc data len: %d", dataLen);
 
