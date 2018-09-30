--- Alc/backends/coreaudio.c.orig	2018-09-06 21:35:18 UTC
+++ Alc/backends/coreaudio.c
@@ -752,7 +752,7 @@ ALCbackendFactory *ALCcoreAudioBackendFa
 static ALCboolean ALCcoreAudioBackendFactory_init(ALCcoreAudioBackendFactory *self);
 static DECLARE_FORWARD(ALCcoreAudioBackendFactory, ALCbackendFactory, void, deinit)
 static ALCboolean ALCcoreAudioBackendFactory_querySupport(ALCcoreAudioBackendFactory *self, ALCbackend_Type type);
-static void ALCcoreAudioBackendFactory_probe(ALCcoreAudioBackendFactory *self, enum DevProbe type);
+static void ALCcoreAudioBackendFactory_probe(ALCcoreAudioBackendFactory *self, enum DevProbe type, al_string *outnames);
 static ALCbackend* ALCcoreAudioBackendFactory_createBackend(ALCcoreAudioBackendFactory *self, ALCdevice *device, ALCbackend_Type type);
 DEFINE_ALCBACKENDFACTORY_VTABLE(ALCcoreAudioBackendFactory);
 
@@ -776,15 +776,13 @@ static ALCboolean ALCcoreAudioBackendFac
     return ALC_FALSE;
 }
 
-static void ALCcoreAudioBackendFactory_probe(ALCcoreAudioBackendFactory* UNUSED(self), enum DevProbe type)
+static void ALCcoreAudioBackendFactory_probe(ALCcoreAudioBackendFactory* UNUSED(self), enum DevProbe type, al_string *outnames)
 {
     switch(type)
     {
         case ALL_DEVICE_PROBE:
-            AppendAllDevicesList(ca_device);
-            break;
         case CAPTURE_DEVICE_PROBE:
-            AppendCaptureDeviceList(ca_device);
+            alstr_append_range(outnames, ca_device, ca_device+sizeof(ca_device));
             break;
     }
 }
