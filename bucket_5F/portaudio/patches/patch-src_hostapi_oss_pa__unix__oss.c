--- src/hostapi/oss/pa_unix_oss.c.orig	2016-10-30 01:23:04 UTC
+++ src/hostapi/oss/pa_unix_oss.c
@@ -535,13 +535,13 @@ static PaError BuildDeviceList( PaOSSHos
      * add it to a linked list.
      * A: Set an arbitrary of 100 devices, should probably be a smarter way. */
 
-    for( i = 0; i < 100; i++ )
+    for( i = -1; i < 100; i++ )
     {
        char deviceName[32];
        PaDeviceInfo *deviceInfo;
        int testResult;
 
-       if( i == 0 )
+       if( i == -1 )
           snprintf(deviceName, sizeof (deviceName), "%s", DEVICE_NAME_BASE);
        else
           snprintf(deviceName, sizeof (deviceName), "%s%d", DEVICE_NAME_BASE, i);
@@ -2043,3 +2043,27 @@ error:
 #endif
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
