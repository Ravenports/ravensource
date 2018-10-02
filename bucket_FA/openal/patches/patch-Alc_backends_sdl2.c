--- Alc/backends/sdl2.c.orig	2018-09-06 21:35:18 UTC
+++ Alc/backends/sdl2.c
@@ -221,7 +221,7 @@ ALCbackendFactory *ALCsdl2BackendFactory
 static ALCboolean ALCsdl2BackendFactory_init(ALCsdl2BackendFactory *self);
 static void ALCsdl2BackendFactory_deinit(ALCsdl2BackendFactory *self);
 static ALCboolean ALCsdl2BackendFactory_querySupport(ALCsdl2BackendFactory *self, ALCbackend_Type type);
-static void ALCsdl2BackendFactory_probe(ALCsdl2BackendFactory *self, enum DevProbe type);
+static void ALCsdl2BackendFactory_probe(ALCsdl2BackendFactory *self, enum DevProbe type, al_string *outnames);
 static ALCbackend* ALCsdl2BackendFactory_createBackend(ALCsdl2BackendFactory *self, ALCdevice *device, ALCbackend_Type type);
 DEFINE_ALCBACKENDFACTORY_VTABLE(ALCsdl2BackendFactory);
 
@@ -252,7 +252,7 @@ static ALCboolean ALCsdl2BackendFactory_
     return ALC_FALSE;
 }
 
-static void ALCsdl2BackendFactory_probe(ALCsdl2BackendFactory* UNUSED(self), enum DevProbe type)
+static void ALCsdl2BackendFactory_probe(ALCsdl2BackendFactory* UNUSED(self), enum DevProbe type, al_string *outnames)
 {
     int num_devices, i;
     al_string name;
@@ -263,12 +263,13 @@ static void ALCsdl2BackendFactory_probe(
     AL_STRING_INIT(name);
     num_devices = SDL_GetNumAudioDevices(SDL_FALSE);
 
-    AppendAllDevicesList(defaultDeviceName);
+    alstr_append_range(outnames, defaultDeviceName, defaultDeviceName+sizeof(defaultDeviceName));
     for(i = 0;i < num_devices;++i)
     {
         alstr_copy_cstr(&name, DEVNAME_PREFIX);
         alstr_append_cstr(&name, SDL_GetAudioDeviceName(i, SDL_FALSE));
-        AppendAllDevicesList(alstr_get_cstr(name));
+        if(!alstr_empty(name))
+            alstr_append_range(outnames, VECTOR_BEGIN(name), VECTOR_END(name)+1);
     }
     alstr_reset(&name);
 }
