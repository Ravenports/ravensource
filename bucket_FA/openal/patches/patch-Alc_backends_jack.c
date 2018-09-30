--- Alc/backends/jack.c.orig	2018-09-06 21:35:18 UTC
+++ Alc/backends/jack.c
@@ -571,12 +571,12 @@ static ALCboolean ALCjackBackendFactory_
     return ALC_FALSE;
 }
 
-static void ALCjackBackendFactory_probe(ALCjackBackendFactory* UNUSED(self), enum DevProbe type)
+static void ALCjackBackendFactory_probe(ALCjackBackendFactory* UNUSED(self), enum DevProbe type, al_string *outnames)
 {
     switch(type)
     {
         case ALL_DEVICE_PROBE:
-            AppendAllDevicesList(jackDevice);
+            alstr_append_range(outnames, jackDevice, jackDevice+sizeof(jackDevice));
             break;
 
         case CAPTURE_DEVICE_PROBE:
