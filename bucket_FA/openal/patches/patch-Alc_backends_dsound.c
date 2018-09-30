--- Alc/backends/dsound.c.orig	2018-09-06 21:35:18 UTC
+++ Alc/backends/dsound.c
@@ -969,11 +969,6 @@ done:
 }
 
 
-static inline void AppendAllDevicesList2(const DevMap *entry)
-{ AppendAllDevicesList(alstr_get_cstr(entry->name)); }
-static inline void AppendCaptureDeviceList2(const DevMap *entry)
-{ AppendCaptureDeviceList(alstr_get_cstr(entry->name)); }
-
 typedef struct ALCdsoundBackendFactory {
     DERIVE_FROM_TYPE(ALCbackendFactory);
 } ALCdsoundBackendFactory;
@@ -984,7 +979,7 @@ ALCbackendFactory *ALCdsoundBackendFacto
 static ALCboolean ALCdsoundBackendFactory_init(ALCdsoundBackendFactory *self);
 static void ALCdsoundBackendFactory_deinit(ALCdsoundBackendFactory *self);
 static ALCboolean ALCdsoundBackendFactory_querySupport(ALCdsoundBackendFactory *self, ALCbackend_Type type);
-static void ALCdsoundBackendFactory_probe(ALCdsoundBackendFactory *self, enum DevProbe type);
+static void ALCdsoundBackendFactory_probe(ALCdsoundBackendFactory *self, enum DevProbe type, al_string *outnames);
 static ALCbackend* ALCdsoundBackendFactory_createBackend(ALCdsoundBackendFactory *self, ALCdevice *device, ALCbackend_Type type);
 DEFINE_ALCBACKENDFACTORY_VTABLE(ALCdsoundBackendFactory);
 
@@ -1028,7 +1023,7 @@ static ALCboolean ALCdsoundBackendFactor
     return ALC_FALSE;
 }
 
-static void ALCdsoundBackendFactory_probe(ALCdsoundBackendFactory* UNUSED(self), enum DevProbe type)
+static void ALCdsoundBackendFactory_probe(ALCdsoundBackendFactory* UNUSED(self), enum DevProbe type, al_string *outnames)
 {
     HRESULT hr, hrcom;
 
@@ -1036,12 +1031,17 @@ static void ALCdsoundBackendFactory_prob
     hrcom = CoInitialize(NULL);
     switch(type)
     {
+#define APPEND_OUTNAME(e) do {                                                \
+    if(!alstr_empty((e)->name))                                               \
+        alstr_append_range(outnames, VECTOR_BEGIN((e)->name),                 \
+                           VECTOR_END((e)->name)+1);                          \
+} while(0)
         case ALL_DEVICE_PROBE:
             clear_devlist(&PlaybackDevices);
             hr = DirectSoundEnumerateW(DSoundEnumDevices, &PlaybackDevices);
             if(FAILED(hr))
                 ERR("Error enumerating DirectSound playback devices (0x%lx)!\n", hr);
-            VECTOR_FOR_EACH(const DevMap, PlaybackDevices, AppendAllDevicesList2);
+            VECTOR_FOR_EACH(const DevMap, PlaybackDevices, APPEND_OUTNAME);
             break;
 
         case CAPTURE_DEVICE_PROBE:
@@ -1049,8 +1049,9 @@ static void ALCdsoundBackendFactory_prob
             hr = DirectSoundCaptureEnumerateW(DSoundEnumDevices, &CaptureDevices);
             if(FAILED(hr))
                 ERR("Error enumerating DirectSound capture devices (0x%lx)!\n", hr);
-            VECTOR_FOR_EACH(const DevMap, CaptureDevices, AppendCaptureDeviceList2);
+            VECTOR_FOR_EACH(const DevMap, CaptureDevices, APPEND_OUTNAME);
             break;
+#undef APPEND_OUTNAME
     }
     if(SUCCEEDED(hrcom))
         CoUninitialize();
