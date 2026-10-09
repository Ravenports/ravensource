--- libs/ctx/libgegl_ctx/ctx.h.orig	2026-09-07 02:51:56 UTC
+++ libs/ctx/libgegl_ctx/ctx.h
@@ -51,7 +51,6 @@ extern "C" {
 #include <string.h>
 #ifndef _WIN32
 #include <strings.h>
-#include <alloca.h>
 #else
 #include <malloc.h>
 #endif
@@ -38681,7 +38680,7 @@ static snd_pcm_t *alsa_open (char *dev,
    if ((r = snd_pcm_open(&h, dev, SND_PCM_STREAM_PLAYBACK, 0) < 0))
            return NULL;
 
-   hwp = (snd_pcm_hw_params_t*)alloca(snd_pcm_hw_params_sizeof());
+   hwp = (snd_pcm_hw_params_t*)__builtin_alloca(snd_pcm_hw_params_sizeof());
    memset(hwp, 0, snd_pcm_hw_params_sizeof());
    snd_pcm_hw_params_any(h, hwp);
 
@@ -38702,7 +38701,7 @@ static snd_pcm_t *alsa_open (char *dev,
    buffer_size = period_size * 4;
    r = snd_pcm_hw_params_set_buffer_size_near(h, hwp, &buffer_size);
    r = snd_pcm_hw_params(h, hwp);
-   swp = (snd_pcm_sw_params_t*)alloca(snd_pcm_hw_params_sizeof());
+   swp = (snd_pcm_sw_params_t*)__builtin_alloca(snd_pcm_hw_params_sizeof());
    memset(hwp, 0, snd_pcm_sw_params_sizeof());
    snd_pcm_sw_params_current(h, swp);
    r = snd_pcm_sw_params_set_avail_min(h, swp, period_size);
