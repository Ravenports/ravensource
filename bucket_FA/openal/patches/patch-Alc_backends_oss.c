--- Alc/backends/oss.c.orig	2018-09-06 21:35:18 UTC
+++ Alc/backends/oss.c
@@ -786,7 +786,7 @@ ALCbackendFactory *ALCossBackendFactory_
 static ALCboolean ALCossBackendFactory_init(ALCossBackendFactory *self);
 static void ALCossBackendFactory_deinit(ALCossBackendFactory *self);
 static ALCboolean ALCossBackendFactory_querySupport(ALCossBackendFactory *self, ALCbackend_Type type);
-static void ALCossBackendFactory_probe(ALCossBackendFactory *self, enum DevProbe type);
+static void ALCossBackendFactory_probe(ALCossBackendFactory *self, enum DevProbe type, al_string *outnames);
 static ALCbackend* ALCossBackendFactory_createBackend(ALCossBackendFactory *self, ALCdevice *device, ALCbackend_Type type);
 DEFINE_ALCBACKENDFACTORY_VTABLE(ALCossBackendFactory);
 
@@ -820,40 +820,31 @@ ALCboolean ALCossBackendFactory_querySup
     return ALC_FALSE;
 }
 
-void ALCossBackendFactory_probe(ALCossBackendFactory* UNUSED(self), enum DevProbe type)
+void ALCossBackendFactory_probe(ALCossBackendFactory* UNUSED(self), enum DevProbe type, al_string *outnames)
 {
-    struct oss_device *cur;
+    struct oss_device *cur = NULL;
     switch(type)
     {
         case ALL_DEVICE_PROBE:
             ALCossListFree(&oss_playback);
             ALCossListPopulate(&oss_playback, DSP_CAP_OUTPUT);
             cur = &oss_playback;
-            while(cur != NULL)
-            {
-#ifdef HAVE_STAT
-                struct stat buf;
-                if(stat(cur->path, &buf) == 0)
-#endif
-                    AppendAllDevicesList(cur->handle);
-                cur = cur->next;
-            }
             break;
 
         case CAPTURE_DEVICE_PROBE:
             ALCossListFree(&oss_capture);
             ALCossListPopulate(&oss_capture, DSP_CAP_INPUT);
             cur = &oss_capture;
-            while(cur != NULL)
-            {
+            break;
+    }
+    while(cur != NULL)
+    {
 #ifdef HAVE_STAT
-                struct stat buf;
-                if(stat(cur->path, &buf) == 0)
+        struct stat buf;
+        if(stat(cur->path, &buf) == 0)
 #endif
-                    AppendCaptureDeviceList(cur->handle);
-                cur = cur->next;
-            }
-            break;
+            alstr_append_range(outnames, cur->handle, cur->handle+strlen(cur->handle)+1);
+        cur = cur->next;
     }
 }
 
