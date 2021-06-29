--- src/common/pa_stream.h.orig	2021-04-01 00:35:42 UTC
+++ src/common/pa_stream.h
@@ -152,6 +152,7 @@ typedef struct PaUtilStreamRepresentatio
     PaStreamFinishedCallback *streamFinishedCallback;
     void *userData;
     PaStreamInfo streamInfo;
+    PaHostApiTypeId hostApiType;
 } PaUtilStreamRepresentation;
 
 
