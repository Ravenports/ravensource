--- include/pcm.h.orig	2024-06-10 09:18:34 UTC
+++ include/pcm.h
@@ -29,6 +29,13 @@
 #ifndef __ALSA_PCM_H
 #define __ALSA_PCM_H
 
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
