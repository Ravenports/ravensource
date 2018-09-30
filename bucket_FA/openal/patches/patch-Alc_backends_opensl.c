--- Alc/backends/opensl.c.orig	2018-09-06 21:35:18 UTC
+++ Alc/backends/opensl.c
@@ -1030,16 +1030,13 @@ static ALCboolean ALCopenslBackendFactor
     return ALC_FALSE;
 }
 
-static void ALCopenslBackendFactory_probe(ALCopenslBackendFactory* UNUSED(self), enum DevProbe type)
+static void ALCopenslBackendFactory_probe(ALCopenslBackendFactory* UNUSED(self), enum DevProbe type, al_string *outnames)
 {
     switch(type)
     {
         case ALL_DEVICE_PROBE:
-            AppendAllDevicesList(opensl_device);
-            break;
-
         case CAPTURE_DEVICE_PROBE:
-            AppendCaptureDeviceList(opensl_device);
+            alstr_append_range(outnames, opensl_device, opensl_device+sizeof(opensl_device));
             break;
     }
 }
