--- Alc/backends/base.h.orig	2018-09-06 21:35:18 UTC
+++ Alc/backends/base.h
@@ -3,6 +3,7 @@
 
 #include "alMain.h"
 #include "threads.h"
+#include "alstring.h"
 
 
 #ifdef __cplusplus
@@ -115,7 +116,7 @@ struct ALCbackendFactoryVtable {
 
     ALCboolean (*const querySupport)(ALCbackendFactory *self, ALCbackend_Type type);
 
-    void (*const probe)(ALCbackendFactory *self, enum DevProbe type);
+    void (*const probe)(ALCbackendFactory *self, enum DevProbe type, al_string *outnames);
 
     ALCbackend* (*const createBackend)(ALCbackendFactory *self, ALCdevice *device, ALCbackend_Type type);
 };
@@ -124,7 +125,7 @@ struct ALCbackendFactoryVtable {
 DECLARE_THUNK(T, ALCbackendFactory, ALCboolean, init)                         \
 DECLARE_THUNK(T, ALCbackendFactory, void, deinit)                             \
 DECLARE_THUNK1(T, ALCbackendFactory, ALCboolean, querySupport, ALCbackend_Type) \
-DECLARE_THUNK1(T, ALCbackendFactory, void, probe, enum DevProbe)              \
+DECLARE_THUNK2(T, ALCbackendFactory, void, probe, enum DevProbe, al_string*)  \
 DECLARE_THUNK2(T, ALCbackendFactory, ALCbackend*, createBackend, ALCdevice*, ALCbackend_Type) \
                                                                               \
 static const struct ALCbackendFactoryVtable T##_ALCbackendFactory_vtable = {  \
@@ -142,7 +143,7 @@ ALCbackendFactory *ALCcoreAudioBackendFa
 ALCbackendFactory *ALCossBackendFactory_getFactory(void);
 ALCbackendFactory *ALCjackBackendFactory_getFactory(void);
 ALCbackendFactory *ALCsolarisBackendFactory_getFactory(void);
-ALCbackendFactory *ALCsndioBackendFactory_getFactory(void);
+ALCbackendFactory *SndioBackendFactory_getFactory(void);
 ALCbackendFactory *ALCqsaBackendFactory_getFactory(void);
 ALCbackendFactory *ALCwasapiBackendFactory_getFactory(void);
 ALCbackendFactory *ALCdsoundBackendFactory_getFactory(void);
