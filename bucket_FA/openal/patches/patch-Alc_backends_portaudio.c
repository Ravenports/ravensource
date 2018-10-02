--- Alc/backends/portaudio.c.orig	2018-09-06 21:35:18 UTC
+++ Alc/backends/portaudio.c
@@ -484,9 +484,8 @@ typedef struct ALCportBackendFactory {
 static ALCboolean ALCportBackendFactory_init(ALCportBackendFactory *self);
 static void ALCportBackendFactory_deinit(ALCportBackendFactory *self);
 static ALCboolean ALCportBackendFactory_querySupport(ALCportBackendFactory *self, ALCbackend_Type type);
-static void ALCportBackendFactory_probe(ALCportBackendFactory *self, enum DevProbe type);
+static void ALCportBackendFactory_probe(ALCportBackendFactory *self, enum DevProbe type, al_string *outnames);
 static ALCbackend* ALCportBackendFactory_createBackend(ALCportBackendFactory *self, ALCdevice *device, ALCbackend_Type type);
-
 DEFINE_ALCBACKENDFACTORY_VTABLE(ALCportBackendFactory);
 
 
@@ -518,15 +517,13 @@ static ALCboolean ALCportBackendFactory_
     return ALC_FALSE;
 }
 
-static void ALCportBackendFactory_probe(ALCportBackendFactory* UNUSED(self), enum DevProbe type)
+static void ALCportBackendFactory_probe(ALCportBackendFactory* UNUSED(self), enum DevProbe type, al_string *outnames)
 {
     switch(type)
     {
         case ALL_DEVICE_PROBE:
-            AppendAllDevicesList(pa_device);
-            break;
         case CAPTURE_DEVICE_PROBE:
-            AppendCaptureDeviceList(pa_device);
+            alstr_append_range(outnames, pa_device, pa_device+sizeof(pa_device));
             break;
     }
 }
