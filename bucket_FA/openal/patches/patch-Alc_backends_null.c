--- Alc/backends/null.c.orig	2018-09-06 21:35:18 UTC
+++ Alc/backends/null.c
@@ -171,7 +171,7 @@ ALCbackendFactory *ALCnullBackendFactory
 static ALCboolean ALCnullBackendFactory_init(ALCnullBackendFactory *self);
 static DECLARE_FORWARD(ALCnullBackendFactory, ALCbackendFactory, void, deinit)
 static ALCboolean ALCnullBackendFactory_querySupport(ALCnullBackendFactory *self, ALCbackend_Type type);
-static void ALCnullBackendFactory_probe(ALCnullBackendFactory *self, enum DevProbe type);
+static void ALCnullBackendFactory_probe(ALCnullBackendFactory *self, enum DevProbe type, al_string *outnames);
 static ALCbackend* ALCnullBackendFactory_createBackend(ALCnullBackendFactory *self, ALCdevice *device, ALCbackend_Type type);
 DEFINE_ALCBACKENDFACTORY_VTABLE(ALCnullBackendFactory);
 
@@ -195,14 +195,13 @@ static ALCboolean ALCnullBackendFactory_
     return ALC_FALSE;
 }
 
-static void ALCnullBackendFactory_probe(ALCnullBackendFactory* UNUSED(self), enum DevProbe type)
+static void ALCnullBackendFactory_probe(ALCnullBackendFactory* UNUSED(self), enum DevProbe type, al_string *outnames)
 {
     switch(type)
     {
         case ALL_DEVICE_PROBE:
-            AppendAllDevicesList(nullDevice);
-            break;
         case CAPTURE_DEVICE_PROBE:
+            alstr_append_range(outnames, nullDevice, nullDevice+sizeof(nullDevice));
             break;
     }
 }
