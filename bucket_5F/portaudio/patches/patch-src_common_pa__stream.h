--- src/common/pa_stream.h.orig	2016-10-30 01:23:04 UTC
+++ src/common/pa_stream.h
@@ -152,6 +152,7 @@ typedef struct PaUtilStreamRepresentatio
     PaStreamFinishedCallback *streamFinishedCallback;
     void *userData;
     PaStreamInfo streamInfo;
+    PaHostApiTypeId hostApiType;
 } PaUtilStreamRepresentation;
 
 
