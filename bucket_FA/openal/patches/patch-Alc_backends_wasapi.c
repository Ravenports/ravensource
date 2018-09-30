--- Alc/backends/wasapi.c.orig	2018-09-06 21:35:18 UTC
+++ Alc/backends/wasapi.c
@@ -1919,11 +1919,6 @@ ALCenum ALCwasapiCapture_captureSamples(
 }
 
 
-static inline void AppendAllDevicesList2(const DevMap *entry)
-{ AppendAllDevicesList(alstr_get_cstr(entry->name)); }
-static inline void AppendCaptureDeviceList2(const DevMap *entry)
-{ AppendCaptureDeviceList(alstr_get_cstr(entry->name)); }
-
 typedef struct ALCwasapiBackendFactory {
     DERIVE_FROM_TYPE(ALCbackendFactory);
 } ALCwasapiBackendFactory;
@@ -1932,7 +1927,7 @@ typedef struct ALCwasapiBackendFactory {
 static ALCboolean ALCwasapiBackendFactory_init(ALCwasapiBackendFactory *self);
 static void ALCwasapiBackendFactory_deinit(ALCwasapiBackendFactory *self);
 static ALCboolean ALCwasapiBackendFactory_querySupport(ALCwasapiBackendFactory *self, ALCbackend_Type type);
-static void ALCwasapiBackendFactory_probe(ALCwasapiBackendFactory *self, enum DevProbe type);
+static void ALCwasapiBackendFactory_probe(ALCwasapiBackendFactory *self, enum DevProbe type, al_string *outnames);
 static ALCbackend* ALCwasapiBackendFactory_createBackend(ALCwasapiBackendFactory *self, ALCdevice *device, ALCbackend_Type type);
 
 DEFINE_ALCBACKENDFACTORY_VTABLE(ALCwasapiBackendFactory);
@@ -1989,7 +1984,7 @@ static ALCboolean ALCwasapiBackendFactor
     return ALC_FALSE;
 }
 
-static void ALCwasapiBackendFactory_probe(ALCwasapiBackendFactory* UNUSED(self), enum DevProbe type)
+static void ALCwasapiBackendFactory_probe(ALCwasapiBackendFactory* UNUSED(self), enum DevProbe type, al_string *outnames)
 {
     ThreadRequest req = { NULL, 0 };
 
@@ -2003,13 +1998,19 @@ static void ALCwasapiBackendFactory_prob
             hr = WaitForResponse(&req);
         if(SUCCEEDED(hr)) switch(type)
         {
+#define APPEND_OUTNAME(e) do {                                                \
+    if(!alstr_empty((e)->name))                                               \
+        alstr_append_range(outnames, VECTOR_BEGIN((e)->name),                 \
+                           VECTOR_END((e)->name)+1);                          \
+} while(0)
         case ALL_DEVICE_PROBE:
-            VECTOR_FOR_EACH(const DevMap, PlaybackDevices, AppendAllDevicesList2);
+            VECTOR_FOR_EACH(const DevMap, PlaybackDevices, APPEND_OUTNAME);
             break;
 
         case CAPTURE_DEVICE_PROBE:
-            VECTOR_FOR_EACH(const DevMap, CaptureDevices, AppendCaptureDeviceList2);
+            VECTOR_FOR_EACH(const DevMap, CaptureDevices, APPEND_OUTNAME);
             break;
+#undef APPEND_OUTNAME
         }
         CloseHandle(req.FinishedEvt);
         req.FinishedEvt = NULL;
