--- Alc/backends/pulseaudio.c.orig	2018-09-06 21:35:18 UTC
+++ Alc/backends/pulseaudio.c
@@ -1760,9 +1760,8 @@ typedef struct ALCpulseBackendFactory {
 static ALCboolean ALCpulseBackendFactory_init(ALCpulseBackendFactory *self);
 static void ALCpulseBackendFactory_deinit(ALCpulseBackendFactory *self);
 static ALCboolean ALCpulseBackendFactory_querySupport(ALCpulseBackendFactory *self, ALCbackend_Type type);
-static void ALCpulseBackendFactory_probe(ALCpulseBackendFactory *self, enum DevProbe type);
+static void ALCpulseBackendFactory_probe(ALCpulseBackendFactory *self, enum DevProbe type, al_string *outnames);
 static ALCbackend* ALCpulseBackendFactory_createBackend(ALCpulseBackendFactory *self, ALCdevice *device, ALCbackend_Type type);
-
 DEFINE_ALCBACKENDFACTORY_VTABLE(ALCpulseBackendFactory);
 
 
@@ -1835,23 +1834,25 @@ static ALCboolean ALCpulseBackendFactory
     return ALC_FALSE;
 }
 
-static void ALCpulseBackendFactory_probe(ALCpulseBackendFactory* UNUSED(self), enum DevProbe type)
+static void ALCpulseBackendFactory_probe(ALCpulseBackendFactory* UNUSED(self), enum DevProbe type, al_string *outnames)
 {
     switch(type)
     {
+#define APPEND_OUTNAME(e) do {                                                \
+    if(!alstr_empty((e)->name))                                               \
+        alstr_append_range(outnames, VECTOR_BEGIN((e)->name),                 \
+                           VECTOR_END((e)->name)+1);                          \
+} while(0)
         case ALL_DEVICE_PROBE:
             ALCpulsePlayback_probeDevices();
-#define APPEND_ALL_DEVICES_LIST(e)  AppendAllDevicesList(alstr_get_cstr((e)->name))
-            VECTOR_FOR_EACH(const DevMap, PlaybackDevices, APPEND_ALL_DEVICES_LIST);
-#undef APPEND_ALL_DEVICES_LIST
+            VECTOR_FOR_EACH(const DevMap, PlaybackDevices, APPEND_OUTNAME);
             break;
 
         case CAPTURE_DEVICE_PROBE:
             ALCpulseCapture_probeDevices();
-#define APPEND_CAPTURE_DEVICE_LIST(e) AppendCaptureDeviceList(alstr_get_cstr((e)->name))
-            VECTOR_FOR_EACH(const DevMap, CaptureDevices, APPEND_CAPTURE_DEVICE_LIST);
-#undef APPEND_CAPTURE_DEVICE_LIST
+            VECTOR_FOR_EACH(const DevMap, CaptureDevices, APPEND_OUTNAME);
             break;
+#undef APPEND_OUTNAME
     }
 }
 
@@ -1899,7 +1900,7 @@ static ALCboolean ALCpulseBackendFactory
     return ALC_FALSE;
 }
 
-static void ALCpulseBackendFactory_probe(ALCpulseBackendFactory* UNUSED(self), enum DevProbe UNUSED(type))
+static void ALCpulseBackendFactory_probe(ALCpulseBackendFactory* UNUSED(self), enum DevProbe UNUSED(type), al_string* UNUSED(outnames))
 {
 }
 
