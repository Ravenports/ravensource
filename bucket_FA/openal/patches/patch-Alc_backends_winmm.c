--- Alc/backends/winmm.c.orig	2018-09-06 21:35:18 UTC
+++ Alc/backends/winmm.c
@@ -700,17 +700,6 @@ static ALCuint ALCwinmmCapture_available
 }
 
 
-static inline void AppendAllDevicesList2(const al_string *name)
-{
-    if(!alstr_empty(*name))
-        AppendAllDevicesList(alstr_get_cstr(*name));
-}
-static inline void AppendCaptureDeviceList2(const al_string *name)
-{
-    if(!alstr_empty(*name))
-        AppendCaptureDeviceList(alstr_get_cstr(*name));
-}
-
 typedef struct ALCwinmmBackendFactory {
     DERIVE_FROM_TYPE(ALCbackendFactory);
 } ALCwinmmBackendFactory;
@@ -719,7 +708,7 @@ typedef struct ALCwinmmBackendFactory {
 static ALCboolean ALCwinmmBackendFactory_init(ALCwinmmBackendFactory *self);
 static void ALCwinmmBackendFactory_deinit(ALCwinmmBackendFactory *self);
 static ALCboolean ALCwinmmBackendFactory_querySupport(ALCwinmmBackendFactory *self, ALCbackend_Type type);
-static void ALCwinmmBackendFactory_probe(ALCwinmmBackendFactory *self, enum DevProbe type);
+static void ALCwinmmBackendFactory_probe(ALCwinmmBackendFactory *self, enum DevProbe type, al_string *outnames);
 static ALCbackend* ALCwinmmBackendFactory_createBackend(ALCwinmmBackendFactory *self, ALCdevice *device, ALCbackend_Type type);
 
 DEFINE_ALCBACKENDFACTORY_VTABLE(ALCwinmmBackendFactory);
@@ -749,19 +738,24 @@ static ALCboolean ALCwinmmBackendFactory
     return ALC_FALSE;
 }
 
-static void ALCwinmmBackendFactory_probe(ALCwinmmBackendFactory* UNUSED(self), enum DevProbe type)
+static void ALCwinmmBackendFactory_probe(ALCwinmmBackendFactory* UNUSED(self), enum DevProbe type, al_string *outnames)
 {
     switch(type)
     {
+#define APPEND_OUTNAME(n) do {                                                \
+    if(!alstr_empty(*(n)))                                                    \
+        alstr_append_range(outnames, VECTOR_BEGIN(*(n)), VECTOR_END(*(n))+1); \
+} while(0)
         case ALL_DEVICE_PROBE:
             ProbePlaybackDevices();
-            VECTOR_FOR_EACH(const al_string, PlaybackDevices, AppendAllDevicesList2);
+            VECTOR_FOR_EACH(const al_string, PlaybackDevices, APPEND_OUTNAME);
             break;
 
         case CAPTURE_DEVICE_PROBE:
             ProbeCaptureDevices();
-            VECTOR_FOR_EACH(const al_string, CaptureDevices, AppendCaptureDeviceList2);
+            VECTOR_FOR_EACH(const al_string, CaptureDevices, APPEND_OUTNAME);
             break;
+#undef APPEND_OUTNAME
     }
 }
 
