--- Alc/backends/qsa.c.orig	2018-09-06 21:35:18 UTC
+++ Alc/backends/qsa.c
@@ -119,6 +119,9 @@ static void deviceList(int type, vector_
     if(max_cards < 0)
         return;
 
+#define FREE_NAME(iter) free((iter)->name)
+    VECTOR_FOR_EACH(DevMap, *devmap, FREE_NAME);
+#undef FREE_NAME
     VECTOR_RESIZE(*devmap, 0, max_cards+1);
 
     entry.name = strdup(qsaDevice);
@@ -989,7 +992,7 @@ typedef struct ALCqsaBackendFactory {
 static ALCboolean ALCqsaBackendFactory_init(ALCqsaBackendFactory* UNUSED(self));
 static void ALCqsaBackendFactory_deinit(ALCqsaBackendFactory* UNUSED(self));
 static ALCboolean ALCqsaBackendFactory_querySupport(ALCqsaBackendFactory* UNUSED(self), ALCbackend_Type type);
-static void ALCqsaBackendFactory_probe(ALCqsaBackendFactory* UNUSED(self), enum DevProbe type);
+static void ALCqsaBackendFactory_probe(ALCqsaBackendFactory* UNUSED(self), enum DevProbe type, al_string *outnames);
 static ALCbackend* ALCqsaBackendFactory_createBackend(ALCqsaBackendFactory* UNUSED(self), ALCdevice *device, ALCbackend_Type type);
 DEFINE_ALCBACKENDFACTORY_VTABLE(ALCqsaBackendFactory);
 
@@ -1016,33 +1019,25 @@ static ALCboolean ALCqsaBackendFactory_q
     return ALC_FALSE;
 }
 
-static void ALCqsaBackendFactory_probe(ALCqsaBackendFactory* UNUSED(self), enum DevProbe type)
+static void ALCqsaBackendFactory_probe(ALCqsaBackendFactory* UNUSED(self), enum DevProbe type, al_string *outnames)
 {
     switch (type)
     {
+#define APPEND_OUTNAME(e) do {                                                \
+    const char *n_ = (e)->name;                                               \
+    if(n_ && n_[0])                                                           \
+        alstr_append_range(outnames, n_, n_+strlen(n_)+1);                    \
+} while(0)
         case ALL_DEVICE_PROBE:
-#define FREE_NAME(iter) free((iter)->name)
-            VECTOR_FOR_EACH(DevMap, DeviceNameMap, FREE_NAME);
-            VECTOR_RESIZE(DeviceNameMap, 0, 0);
-#undef FREE_NAME
-
             deviceList(SND_PCM_CHANNEL_PLAYBACK, &DeviceNameMap);
-#define APPEND_DEVICE(iter) AppendAllDevicesList((iter)->name)
-            VECTOR_FOR_EACH(const DevMap, DeviceNameMap, APPEND_DEVICE);
-#undef APPEND_DEVICE
+            VECTOR_FOR_EACH(const DevMap, DeviceNameMap, APPEND_OUTNAME);
             break;
 
         case CAPTURE_DEVICE_PROBE:
-#define FREE_NAME(iter) free((iter)->name)
-            VECTOR_FOR_EACH(DevMap, CaptureNameMap, FREE_NAME);
-            VECTOR_RESIZE(CaptureNameMap, 0, 0);
-#undef FREE_NAME
-
             deviceList(SND_PCM_CHANNEL_CAPTURE, &CaptureNameMap);
-#define APPEND_DEVICE(iter) AppendCaptureDeviceList((iter)->name)
-            VECTOR_FOR_EACH(const DevMap, CaptureNameMap, APPEND_DEVICE);
-#undef APPEND_DEVICE
+            VECTOR_FOR_EACH(const DevMap, CaptureNameMap, APPEND_OUTNAME);
             break;
+#undef APPEND_OUTNAME
     }
 }
 
