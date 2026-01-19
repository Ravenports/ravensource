--- include/pcm.h.orig	2026-01-13 07:12:40 UTC
+++ include/pcm.h
@@ -35,6 +35,13 @@
 #ifndef __ALSA_PCM_H
 #define __ALSA_PCM_H /**< header include loop protection */
 
+#ifndef ESTRPIPE
+#define ESTRPIPE EPIPE
+#endif
+#ifndef EBADFD
+#define EBADFD EBADF
+#endif
+
 #ifdef __cplusplus
 extern "C" {
 #endif
