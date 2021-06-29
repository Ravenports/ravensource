--- src/hostapi/oss/pa_unix_oss.c.orig	2021-04-01 00:35:42 UTC
+++ src/hostapi/oss/pa_unix_oss.c
@@ -2032,6 +2032,30 @@ error:
     return result;
 }
 
+const char *PaOSS_GetStreamInputDevice( PaStream* s )
+{
+    PaOssStream *stream = (PaOssStream*)s;
+
+    if( stream->capture )
+    {
+      return stream->capture->devName;
+    }
+
+   return NULL;
+}
+
+const char *PaOSS_GetStreamOutputDevice( PaStream* s )
+{
+    PaOssStream *stream = (PaOssStream*)s;
+
+    if( stream->playback )
+    {
+      return stream->playback->devName;
+    }
+
+   return NULL;
+}
+
 
 /* TODO: Compute number of allocated bytes somewhere else, can we use ODELAY with capture */
 static signed long GetStreamWriteAvailable( PaStream* s )
