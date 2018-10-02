--- Alc/backends/wave.c.orig	2018-09-06 21:35:18 UTC
+++ Alc/backends/wave.c
@@ -403,7 +403,7 @@ ALCbackendFactory *ALCwaveBackendFactory
 static ALCboolean ALCwaveBackendFactory_init(ALCwaveBackendFactory *self);
 static DECLARE_FORWARD(ALCwaveBackendFactory, ALCbackendFactory, void, deinit)
 static ALCboolean ALCwaveBackendFactory_querySupport(ALCwaveBackendFactory *self, ALCbackend_Type type);
-static void ALCwaveBackendFactory_probe(ALCwaveBackendFactory *self, enum DevProbe type);
+static void ALCwaveBackendFactory_probe(ALCwaveBackendFactory *self, enum DevProbe type, al_string *outnames);
 static ALCbackend* ALCwaveBackendFactory_createBackend(ALCwaveBackendFactory *self, ALCdevice *device, ALCbackend_Type type);
 DEFINE_ALCBACKENDFACTORY_VTABLE(ALCwaveBackendFactory);
 
@@ -427,12 +427,12 @@ static ALCboolean ALCwaveBackendFactory_
     return ALC_FALSE;
 }
 
-static void ALCwaveBackendFactory_probe(ALCwaveBackendFactory* UNUSED(self), enum DevProbe type)
+static void ALCwaveBackendFactory_probe(ALCwaveBackendFactory* UNUSED(self), enum DevProbe type, al_string *outnames)
 {
     switch(type)
     {
         case ALL_DEVICE_PROBE:
-            AppendAllDevicesList(waveDevice);
+            alstr_append_range(outnames, waveDevice, waveDevice+sizeof(waveDevice));
             break;
         case CAPTURE_DEVICE_PROBE:
             break;
