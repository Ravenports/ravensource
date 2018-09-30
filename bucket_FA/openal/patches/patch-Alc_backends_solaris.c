--- Alc/backends/solaris.c.orig	2018-09-06 21:35:18 UTC
+++ Alc/backends/solaris.c
@@ -302,7 +302,7 @@ ALCbackendFactory *ALCsolarisBackendFact
 static ALCboolean ALCsolarisBackendFactory_init(ALCsolarisBackendFactory *self);
 static DECLARE_FORWARD(ALCsolarisBackendFactory, ALCbackendFactory, void, deinit)
 static ALCboolean ALCsolarisBackendFactory_querySupport(ALCsolarisBackendFactory *self, ALCbackend_Type type);
-static void ALCsolarisBackendFactory_probe(ALCsolarisBackendFactory *self, enum DevProbe type);
+static void ALCsolarisBackendFactory_probe(ALCsolarisBackendFactory *self, enum DevProbe type, al_string *outnames);
 static ALCbackend* ALCsolarisBackendFactory_createBackend(ALCsolarisBackendFactory *self, ALCdevice *device, ALCbackend_Type type);
 DEFINE_ALCBACKENDFACTORY_VTABLE(ALCsolarisBackendFactory);
 
@@ -327,7 +327,7 @@ static ALCboolean ALCsolarisBackendFacto
     return ALC_FALSE;
 }
 
-static void ALCsolarisBackendFactory_probe(ALCsolarisBackendFactory* UNUSED(self), enum DevProbe type)
+static void ALCsolarisBackendFactory_probe(ALCsolarisBackendFactory* UNUSED(self), enum DevProbe type, al_string *outnames)
 {
     switch(type)
     {
@@ -337,7 +337,7 @@ static void ALCsolarisBackendFactory_pro
             struct stat buf;
             if(stat(solaris_driver, &buf) == 0)
 #endif
-                AppendAllDevicesList(solaris_device);
+                alstr_append_range(outnames, solaris_device, solaris_device+sizeof(solaris_device));
         }
         break;
 
