--- Alc/backends/alsa.c.orig	2018-09-06 21:35:18 UTC
+++ Alc/backends/alsa.c
@@ -1375,11 +1375,6 @@ static ClockLatency ALCcaptureAlsa_getCl
 }
 
 
-static inline void AppendAllDevicesList2(const DevMap *entry)
-{ AppendAllDevicesList(alstr_get_cstr(entry->name)); }
-static inline void AppendCaptureDeviceList2(const DevMap *entry)
-{ AppendCaptureDeviceList(alstr_get_cstr(entry->name)); }
-
 typedef struct ALCalsaBackendFactory {
     DERIVE_FROM_TYPE(ALCbackendFactory);
 } ALCalsaBackendFactory;
@@ -1417,19 +1412,25 @@ static ALCboolean ALCalsaBackendFactory_
     return ALC_FALSE;
 }
 
-static void ALCalsaBackendFactory_probe(ALCalsaBackendFactory* UNUSED(self), enum DevProbe type)
+static void ALCalsaBackendFactory_probe(ALCalsaBackendFactory* UNUSED(self), enum DevProbe type, al_string *outnames)
 {
     switch(type)
     {
+#define APPEND_OUTNAME(i) do {                                                \
+    if(!alstr_empty((i)->name))                                               \
+        alstr_append_range(outnames, VECTOR_BEGIN((i)->name),                 \
+                           VECTOR_END((i)->name)+1);                          \
+} while(0)
         case ALL_DEVICE_PROBE:
             probe_devices(SND_PCM_STREAM_PLAYBACK, &PlaybackDevices);
-            VECTOR_FOR_EACH(const DevMap, PlaybackDevices, AppendAllDevicesList2);
+            VECTOR_FOR_EACH(const DevMap, PlaybackDevices, APPEND_OUTNAME);
             break;
 
         case CAPTURE_DEVICE_PROBE:
             probe_devices(SND_PCM_STREAM_CAPTURE, &CaptureDevices);
-            VECTOR_FOR_EACH(const DevMap, CaptureDevices, AppendCaptureDeviceList2);
+            VECTOR_FOR_EACH(const DevMap, CaptureDevices, APPEND_OUTNAME);
             break;
+#undef APPEND_OUTNAME
     }
 }
 
