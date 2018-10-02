--- Alc/backends/sndio.c.orig	2018-09-06 21:35:18 UTC
+++ Alc/backends/sndio.c
@@ -27,15 +27,17 @@
 #include "alMain.h"
 #include "alu.h"
 #include "threads.h"
+#include "ringbuffer.h"
 
 #include "backends/base.h"
 
 #include <sndio.h>
 
 
+static const ALCchar sndio_device[] = "SndIO Default";
 
 
-typedef struct ALCsndioBackend {
+typedef struct SndioPlayback {
     DERIVE_FROM_TYPE(ALCbackend);
 
     struct sio_hdl *sndHandle;
@@ -45,40 +47,37 @@ typedef struct ALCsndioBackend {
 
     ATOMIC(int) killNow;
     althrd_t thread;
-} ALCsndioBackend;
-
-static int ALCsndioBackend_mixerProc(void *ptr);
-
-static void ALCsndioBackend_Construct(ALCsndioBackend *self, ALCdevice *device);
-static void ALCsndioBackend_Destruct(ALCsndioBackend *self);
-static ALCenum ALCsndioBackend_open(ALCsndioBackend *self, const ALCchar *name);
-static ALCboolean ALCsndioBackend_reset(ALCsndioBackend *self);
-static ALCboolean ALCsndioBackend_start(ALCsndioBackend *self);
-static void ALCsndioBackend_stop(ALCsndioBackend *self);
-static DECLARE_FORWARD2(ALCsndioBackend, ALCbackend, ALCenum, captureSamples, void*, ALCuint)
-static DECLARE_FORWARD(ALCsndioBackend, ALCbackend, ALCuint, availableSamples)
-static DECLARE_FORWARD(ALCsndioBackend, ALCbackend, ClockLatency, getClockLatency)
-static DECLARE_FORWARD(ALCsndioBackend, ALCbackend, void, lock)
-static DECLARE_FORWARD(ALCsndioBackend, ALCbackend, void, unlock)
-DECLARE_DEFAULT_ALLOCATORS(ALCsndioBackend)
+} SndioPlayback;
 
-DEFINE_ALCBACKEND_VTABLE(ALCsndioBackend);
+static int SndioPlayback_mixerProc(void *ptr);
 
+static void SndioPlayback_Construct(SndioPlayback *self, ALCdevice *device);
+static void SndioPlayback_Destruct(SndioPlayback *self);
+static ALCenum SndioPlayback_open(SndioPlayback *self, const ALCchar *name);
+static ALCboolean SndioPlayback_reset(SndioPlayback *self);
+static ALCboolean SndioPlayback_start(SndioPlayback *self);
+static void SndioPlayback_stop(SndioPlayback *self);
+static DECLARE_FORWARD2(SndioPlayback, ALCbackend, ALCenum, captureSamples, void*, ALCuint)
+static DECLARE_FORWARD(SndioPlayback, ALCbackend, ALCuint, availableSamples)
+static DECLARE_FORWARD(SndioPlayback, ALCbackend, ClockLatency, getClockLatency)
+static DECLARE_FORWARD(SndioPlayback, ALCbackend, void, lock)
+static DECLARE_FORWARD(SndioPlayback, ALCbackend, void, unlock)
+DECLARE_DEFAULT_ALLOCATORS(SndioPlayback)
 
-static const ALCchar sndio_device[] = "SndIO Default";
+DEFINE_ALCBACKEND_VTABLE(SndioPlayback);
 
 
-static void ALCsndioBackend_Construct(ALCsndioBackend *self, ALCdevice *device)
+static void SndioPlayback_Construct(SndioPlayback *self, ALCdevice *device)
 {
     ALCbackend_Construct(STATIC_CAST(ALCbackend, self), device);
-    SET_VTABLE2(ALCsndioBackend, ALCbackend, self);
+    SET_VTABLE2(SndioPlayback, ALCbackend, self);
 
     self->sndHandle = NULL;
     self->mix_data = NULL;
     ATOMIC_INIT(&self->killNow, AL_TRUE);
 }
 
-static void ALCsndioBackend_Destruct(ALCsndioBackend *self)
+static void SndioPlayback_Destruct(SndioPlayback *self)
 {
     if(self->sndHandle)
         sio_close(self->sndHandle);
@@ -91,9 +90,9 @@ static void ALCsndioBackend_Destruct(ALC
 }
 
 
-static int ALCsndioBackend_mixerProc(void *ptr)
+static int SndioPlayback_mixerProc(void *ptr)
 {
-    ALCsndioBackend *self = (ALCsndioBackend*)ptr;
+    SndioPlayback *self = (SndioPlayback*)ptr;
     ALCdevice *device = STATIC_CAST(ALCbackend, self)->mDevice;
     ALsizei frameSize;
     size_t wrote;
@@ -109,9 +108,9 @@ static int ALCsndioBackend_mixerProc(voi
         ALsizei len = self->data_size;
         ALubyte *WritePtr = self->mix_data;
 
-        ALCsndioBackend_lock(self);
+        SndioPlayback_lock(self);
         aluMixData(device, WritePtr, len/frameSize);
-        ALCsndioBackend_unlock(self);
+        SndioPlayback_unlock(self);
         while(len > 0 && !ATOMIC_LOAD(&self->killNow, almemory_order_acquire))
         {
             wrote = sio_write(self->sndHandle, WritePtr, len);
@@ -133,7 +132,7 @@ static int ALCsndioBackend_mixerProc(voi
 }
 
 
-static ALCenum ALCsndioBackend_open(ALCsndioBackend *self, const ALCchar *name)
+static ALCenum SndioPlayback_open(SndioPlayback *self, const ALCchar *name)
 {
     ALCdevice *device = STATIC_CAST(ALCbackend,self)->mDevice;
 
@@ -154,7 +153,7 @@ static ALCenum ALCsndioBackend_open(ALCs
     return ALC_NO_ERROR;
 }
 
-static ALCboolean ALCsndioBackend_reset(ALCsndioBackend *self)
+static ALCboolean SndioPlayback_reset(SndioPlayback *self)
 {
     ALCdevice *device = STATIC_CAST(ALCbackend,self)->mDevice;
     struct sio_par par;
@@ -239,7 +238,7 @@ static ALCboolean ALCsndioBackend_reset(
     return ALC_TRUE;
 }
 
-static ALCboolean ALCsndioBackend_start(ALCsndioBackend *self)
+static ALCboolean SndioPlayback_start(SndioPlayback *self)
 {
     ALCdevice *device = STATIC_CAST(ALCbackend,self)->mDevice;
 
@@ -256,7 +255,7 @@ static ALCboolean ALCsndioBackend_start(
     }
 
     ATOMIC_STORE(&self->killNow, AL_FALSE, almemory_order_release);
-    if(althrd_create(&self->thread, ALCsndioBackend_mixerProc, self) != althrd_success)
+    if(althrd_create(&self->thread, SndioPlayback_mixerProc, self) != althrd_success)
     {
         sio_stop(self->sndHandle);
         return ALC_FALSE;
@@ -265,7 +264,7 @@ static ALCboolean ALCsndioBackend_start(
     return ALC_TRUE;
 }
 
-static void ALCsndioBackend_stop(ALCsndioBackend *self)
+static void SndioPlayback_stop(SndioPlayback *self)
 {
     int res;
 
@@ -281,59 +280,318 @@ static void ALCsndioBackend_stop(ALCsndi
 }
 
 
-typedef struct ALCsndioBackendFactory {
-    DERIVE_FROM_TYPE(ALCbackendFactory);
-} ALCsndioBackendFactory;
-#define ALCSNDIOBACKENDFACTORY_INITIALIZER { { GET_VTABLE2(ALCsndioBackendFactory, ALCbackendFactory) } }
+typedef struct SndioCapture {
+    DERIVE_FROM_TYPE(ALCbackend);
+
+    struct sio_hdl *sndHandle;
+
+    ll_ringbuffer_t *ring;
+
+    ATOMIC(int) killNow;
+    althrd_t thread;
+} SndioCapture;
+
+static int SndioCapture_recordProc(void *ptr);
 
-ALCbackendFactory *ALCsndioBackendFactory_getFactory(void);
+static void SndioCapture_Construct(SndioCapture *self, ALCdevice *device);
+static void SndioCapture_Destruct(SndioCapture *self);
+static ALCenum SndioCapture_open(SndioCapture *self, const ALCchar *name);
+static DECLARE_FORWARD(SndioCapture, ALCbackend, ALCboolean, reset)
+static ALCboolean SndioCapture_start(SndioCapture *self);
+static void SndioCapture_stop(SndioCapture *self);
+static ALCenum SndioCapture_captureSamples(SndioCapture *self, void *buffer, ALCuint samples);
+static ALCuint SndioCapture_availableSamples(SndioCapture *self);
+static DECLARE_FORWARD(SndioCapture, ALCbackend, ClockLatency, getClockLatency)
+static DECLARE_FORWARD(SndioCapture, ALCbackend, void, lock)
+static DECLARE_FORWARD(SndioCapture, ALCbackend, void, unlock)
+DECLARE_DEFAULT_ALLOCATORS(SndioCapture)
 
-static ALCboolean ALCsndioBackendFactory_init(ALCsndioBackendFactory *self);
-static DECLARE_FORWARD(ALCsndioBackendFactory, ALCbackendFactory, void, deinit)
-static ALCboolean ALCsndioBackendFactory_querySupport(ALCsndioBackendFactory *self, ALCbackend_Type type);
-static void ALCsndioBackendFactory_probe(ALCsndioBackendFactory *self, enum DevProbe type);
-static ALCbackend* ALCsndioBackendFactory_createBackend(ALCsndioBackendFactory *self, ALCdevice *device, ALCbackend_Type type);
-DEFINE_ALCBACKENDFACTORY_VTABLE(ALCsndioBackendFactory);
+DEFINE_ALCBACKEND_VTABLE(SndioCapture);
 
 
-ALCbackendFactory *ALCsndioBackendFactory_getFactory(void)
+static void SndioCapture_Construct(SndioCapture *self, ALCdevice *device)
 {
-    static ALCsndioBackendFactory factory = ALCSNDIOBACKENDFACTORY_INITIALIZER;
-    return STATIC_CAST(ALCbackendFactory, &factory);
+    ALCbackend_Construct(STATIC_CAST(ALCbackend, self), device);
+    SET_VTABLE2(SndioCapture, ALCbackend, self);
+
+    self->sndHandle = NULL;
+    self->ring = NULL;
+    ATOMIC_INIT(&self->killNow, AL_TRUE);
+}
+
+static void SndioCapture_Destruct(SndioCapture *self)
+{
+    if(self->sndHandle)
+        sio_close(self->sndHandle);
+    self->sndHandle = NULL;
+
+    ll_ringbuffer_free(self->ring);
+    self->ring = NULL;
+
+    ALCbackend_Destruct(STATIC_CAST(ALCbackend, self));
+}
+
+
+static int SndioCapture_recordProc(void* ptr)
+{
+    SndioCapture *self = (SndioCapture*)ptr;
+    ALCdevice *device = STATIC_CAST(ALCbackend, self)->mDevice;
+    ALsizei frameSize;
+
+    SetRTPriority();
+    althrd_setname(althrd_current(), RECORD_THREAD_NAME);
+
+    frameSize = FrameSizeFromDevFmt(device->FmtChans, device->FmtType, device->AmbiOrder);
+
+    while(!ATOMIC_LOAD(&self->killNow, almemory_order_acquire) &&
+          ATOMIC_LOAD(&device->Connected, almemory_order_acquire))
+    {
+        ll_ringbuffer_data_t data[2];
+        size_t total, todo;
+
+        ll_ringbuffer_get_write_vector(self->ring, data);
+        todo = data[0].len + data[1].len;
+        if(todo == 0)
+        {
+            static char junk[4096];
+            sio_read(self->sndHandle, junk, minz(sizeof(junk)/frameSize, device->UpdateSize)*frameSize);
+            continue;
+        }
+
+        total = 0;
+        data[0].len *= frameSize;
+        data[1].len *= frameSize;
+        todo = minz(todo, device->UpdateSize) * frameSize;
+        while(total < todo)
+        {
+            size_t got;
+
+            if(!data[0].len)
+                data[0] = data[1];
+
+            got = sio_read(self->sndHandle, data[0].buf, minz(todo-total, data[0].len));
+            if(!got)
+            {
+                SndioCapture_lock(self);
+                aluHandleDisconnect(device, "Failed to read capture samples");
+                SndioCapture_unlock(self);
+                break;
+            }
+
+            data[0].buf += got;
+            data[0].len -= got;
+            total += got;
+        }
+        ll_ringbuffer_write_advance(self->ring, total / frameSize);
+    }
+
+    return 0;
+}
+
+
+static ALCenum SndioCapture_open(SndioCapture *self, const ALCchar *name)
+{
+    ALCdevice *device = STATIC_CAST(ALCbackend,self)->mDevice;
+    struct sio_par par;
+
+    if(!name)
+        name = sndio_device;
+    else if(strcmp(name, sndio_device) != 0)
+        return ALC_INVALID_VALUE;
+
+    self->sndHandle = sio_open(NULL, SIO_REC, 0);
+    if(self->sndHandle == NULL)
+    {
+        ERR("Could not open device\n");
+        return ALC_INVALID_VALUE;
+    }
+
+    sio_initpar(&par);
+
+    switch(device->FmtType)
+    {
+        case DevFmtByte:
+            par.bps = 1;
+            par.sig = 1;
+            break;
+        case DevFmtUByte:
+            par.bps = 1;
+            par.sig = 0;
+            break;
+        case DevFmtShort:
+            par.bps = 2;
+            par.sig = 1;
+            break;
+        case DevFmtUShort:
+            par.bps = 2;
+            par.sig = 0;
+            break;
+        case DevFmtInt:
+            par.bps = 4;
+            par.sig = 1;
+            break;
+        case DevFmtUInt:
+            par.bps = 4;
+            par.sig = 0;
+            break;
+        case DevFmtFloat:
+            ERR("%s capture samples not supported\n", DevFmtTypeString(device->FmtType));
+            return ALC_INVALID_VALUE;
+    }
+    par.bits = par.bps * 8;
+    par.le = SIO_LE_NATIVE;
+    par.msb = SIO_LE_NATIVE ? 0 : 1;
+    par.rchan = ChannelsFromDevFmt(device->FmtChans, device->AmbiOrder);
+    par.rate = device->Frequency;
+
+    par.appbufsz = maxu(device->UpdateSize*device->NumUpdates, (device->Frequency+9)/10);
+    par.round = clampu(par.appbufsz/device->NumUpdates, (device->Frequency+99)/100,
+                       (device->Frequency+19)/20);
+
+    device->UpdateSize = par.round;
+    device->NumUpdates = maxu(par.appbufsz/par.round, 1);
+
+    if(!sio_setpar(self->sndHandle, &par) || !sio_getpar(self->sndHandle, &par))
+    {
+        ERR("Failed to set device parameters\n");
+        return ALC_INVALID_VALUE;
+    }
+
+    if(par.bits != par.bps*8)
+    {
+        ERR("Padded samples not supported (%u of %u bits)\n", par.bits, par.bps*8);
+        return ALC_INVALID_VALUE;
+    }
+
+    if(!((device->FmtType == DevFmtByte && par.bits == 8 && par.sig != 0) ||
+         (device->FmtType == DevFmtUByte && par.bits == 8 && par.sig == 0) ||
+         (device->FmtType == DevFmtShort && par.bits == 16 && par.sig != 0) ||
+         (device->FmtType == DevFmtUShort && par.bits == 16 && par.sig == 0) ||
+         (device->FmtType == DevFmtInt && par.bits == 32 && par.sig != 0) ||
+         (device->FmtType == DevFmtUInt && par.bits == 32 && par.sig == 0)) ||
+       ChannelsFromDevFmt(device->FmtChans, device->AmbiOrder) != (ALsizei)par.rchan ||
+       device->Frequency != par.rate)
+    {
+        ERR("Failed to set format %s %s %uhz, got %c%u %u-channel %uhz instead\n",
+            DevFmtTypeString(device->FmtType), DevFmtChannelsString(device->FmtChans),
+            device->Frequency, par.sig?'s':'u', par.bits, par.rchan, par.rate);
+        return ALC_INVALID_VALUE;
+    }
+
+    self->ring = ll_ringbuffer_create(device->UpdateSize*device->NumUpdates, par.bps*par.rchan, 0);
+    if(!self->ring)
+    {
+        ERR("Failed to allocate %u-byte ringbuffer\n",
+            device->UpdateSize*device->NumUpdates*par.bps*par.rchan);
+        return ALC_OUT_OF_MEMORY;
+    }
+
+    SetDefaultChannelOrder(device);
+
+    alstr_copy_cstr(&device->DeviceName, name);
+
+    return ALC_NO_ERROR;
+}
+
+static ALCboolean SndioCapture_start(SndioCapture *self)
+{
+    if(!sio_start(self->sndHandle))
+    {
+        ERR("Error starting playback\n");
+        return ALC_FALSE;
+    }
+
+    ATOMIC_STORE(&self->killNow, AL_FALSE, almemory_order_release);
+    if(althrd_create(&self->thread, SndioCapture_recordProc, self) != althrd_success)
+    {
+        sio_stop(self->sndHandle);
+        return ALC_FALSE;
+    }
+
+    return ALC_TRUE;
+}
+
+static void SndioCapture_stop(SndioCapture *self)
+{
+    int res;
+
+    if(ATOMIC_EXCHANGE(&self->killNow, AL_TRUE, almemory_order_acq_rel))
+        return;
+    althrd_join(self->thread, &res);
+
+    if(!sio_stop(self->sndHandle))
+        ERR("Error stopping device\n");
+}
+
+static ALCenum SndioCapture_captureSamples(SndioCapture *self, void *buffer, ALCuint samples)
+{
+    ll_ringbuffer_read(self->ring, buffer, samples);
+    return ALC_NO_ERROR;
 }
 
+static ALCuint SndioCapture_availableSamples(SndioCapture *self)
+{
+    return ll_ringbuffer_read_space(self->ring);
+}
+
+
+typedef struct SndioBackendFactory {
+    DERIVE_FROM_TYPE(ALCbackendFactory);
+} SndioBackendFactory;
+#define SNDIOBACKENDFACTORY_INITIALIZER { { GET_VTABLE2(SndioBackendFactory, ALCbackendFactory) } }
+
+ALCbackendFactory *SndioBackendFactory_getFactory(void);
 
-static ALCboolean ALCsndioBackendFactory_init(ALCsndioBackendFactory* UNUSED(self))
+static ALCboolean SndioBackendFactory_init(SndioBackendFactory *self);
+static DECLARE_FORWARD(SndioBackendFactory, ALCbackendFactory, void, deinit)
+static ALCboolean SndioBackendFactory_querySupport(SndioBackendFactory *self, ALCbackend_Type type);
+static void SndioBackendFactory_probe(SndioBackendFactory *self, enum DevProbe type, al_string *outnames);
+static ALCbackend* SndioBackendFactory_createBackend(SndioBackendFactory *self, ALCdevice *device, ALCbackend_Type type);
+DEFINE_ALCBACKENDFACTORY_VTABLE(SndioBackendFactory);
+
+ALCbackendFactory *SndioBackendFactory_getFactory(void)
+{
+    static SndioBackendFactory factory = SNDIOBACKENDFACTORY_INITIALIZER;
+    return STATIC_CAST(ALCbackendFactory, &factory);
+}
+
+static ALCboolean SndioBackendFactory_init(SndioBackendFactory* UNUSED(self))
 {
     /* No dynamic loading */
     return ALC_TRUE;
 }
 
-static ALCboolean ALCsndioBackendFactory_querySupport(ALCsndioBackendFactory* UNUSED(self), ALCbackend_Type type)
+static ALCboolean SndioBackendFactory_querySupport(SndioBackendFactory* UNUSED(self), ALCbackend_Type type)
 {
-    if(type == ALCbackend_Playback)
+    if(type == ALCbackend_Playback || type == ALCbackend_Capture)
         return ALC_TRUE;
     return ALC_FALSE;
 }
 
-static void ALCsndioBackendFactory_probe(ALCsndioBackendFactory* UNUSED(self), enum DevProbe type)
+static void SndioBackendFactory_probe(SndioBackendFactory* UNUSED(self), enum DevProbe type, al_string *outnames)
 {
     switch(type)
     {
         case ALL_DEVICE_PROBE:
-            AppendAllDevicesList(sndio_device);
-            break;
         case CAPTURE_DEVICE_PROBE:
+            alstr_append_range(outnames, sndio_device, sndio_device+sizeof(sndio_device));
             break;
     }
 }
 
-static ALCbackend* ALCsndioBackendFactory_createBackend(ALCsndioBackendFactory* UNUSED(self), ALCdevice *device, ALCbackend_Type type)
+static ALCbackend* SndioBackendFactory_createBackend(SndioBackendFactory* UNUSED(self), ALCdevice *device, ALCbackend_Type type)
 {
     if(type == ALCbackend_Playback)
     {
-        ALCsndioBackend *backend;
-        NEW_OBJ(backend, ALCsndioBackend)(device);
+        SndioPlayback *backend;
+        NEW_OBJ(backend, SndioPlayback)(device);
+        if(!backend) return NULL;
+        return STATIC_CAST(ALCbackend, backend);
+    }
+    if(type == ALCbackend_Capture)
+    {
+        SndioCapture *backend;
+        NEW_OBJ(backend, SndioCapture)(device);
         if(!backend) return NULL;
         return STATIC_CAST(ALCbackend, backend);
     }
