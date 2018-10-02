--- Alc/ALc.c.orig	2018-09-06 21:35:18 UTC
+++ Alc/ALc.c
@@ -79,7 +79,7 @@ static struct BackendInfo BackendList[]
     { "solaris", ALCsolarisBackendFactory_getFactory },
 #endif
 #ifdef HAVE_SNDIO
-    { "sndio", ALCsndioBackendFactory_getFactory },
+    { "sndio", SndioBackendFactory_getFactory },
 #endif
 #ifdef HAVE_OSS
     { "oss", ALCossBackendFactory_getFactory },
@@ -656,9 +656,9 @@ static const struct {
 
     DECL(AL_DEDICATED_GAIN),
 
-    DECL(AL_AUTOWAH_ATTACK_TIME),
-    DECL(AL_AUTOWAH_RELEASE_TIME),
-    DECL(AL_AUTOWAH_RESONANCE),
+    DECL(AL_AUTOWAH_ATTACK_TIME),
+    DECL(AL_AUTOWAH_RELEASE_TIME),
+    DECL(AL_AUTOWAH_RESONANCE),
     DECL(AL_AUTOWAH_PEAK_GAIN),
 
     DECL(AL_NUM_RESAMPLERS_SOFT),
@@ -1314,7 +1314,7 @@ static void ProbeDevices(al_string *list
     if(backendinfo->getFactory)
     {
         ALCbackendFactory *factory = backendinfo->getFactory();
-        V(factory,probe)(type);
+        V(factory,probe)(type, list);
     }
 
     UnlockLists();
@@ -1324,17 +1324,6 @@ static void ProbeAllDevicesList(void)
 static void ProbeCaptureDeviceList(void)
 { ProbeDevices(&alcCaptureDeviceList, &CaptureBackend, CAPTURE_DEVICE_PROBE); }
 
-static void AppendDevice(const ALCchar *name, al_string *devnames)
-{
-    size_t len = strlen(name);
-    if(len > 0)
-        alstr_append_range(devnames, name, name+len+1);
-}
-void AppendAllDevicesList(const ALCchar *name)
-{ AppendDevice(name, &alcAllDevicesList); }
-void AppendCaptureDeviceList(const ALCchar *name)
-{ AppendDevice(name, &alcCaptureDeviceList); }
-
 
 /************************************************
  * Device format information
