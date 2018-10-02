--- Alc/backends/loopback.c.orig	2018-09-06 21:35:18 UTC
+++ Alc/backends/loopback.c
@@ -87,7 +87,7 @@ ALCbackendFactory *ALCloopbackFactory_ge
 static ALCboolean ALCloopbackFactory_init(ALCloopbackFactory *self);
 static DECLARE_FORWARD(ALCloopbackFactory, ALCbackendFactory, void, deinit)
 static ALCboolean ALCloopbackFactory_querySupport(ALCloopbackFactory *self, ALCbackend_Type type);
-static void ALCloopbackFactory_probe(ALCloopbackFactory *self, enum DevProbe type);
+static void ALCloopbackFactory_probe(ALCloopbackFactory *self, enum DevProbe type, al_string *outnames);
 static ALCbackend* ALCloopbackFactory_createBackend(ALCloopbackFactory *self, ALCdevice *device, ALCbackend_Type type);
 DEFINE_ALCBACKENDFACTORY_VTABLE(ALCloopbackFactory);
 
@@ -110,7 +110,7 @@ static ALCboolean ALCloopbackFactory_que
     return ALC_FALSE;
 }
 
-static void ALCloopbackFactory_probe(ALCloopbackFactory* UNUSED(self), enum DevProbe UNUSED(type))
+static void ALCloopbackFactory_probe(ALCloopbackFactory* UNUSED(self), enum DevProbe UNUSED(type), al_string* UNUSED(outnames))
 {
 }
 
