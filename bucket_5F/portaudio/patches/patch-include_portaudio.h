$OpenBSD: patch-include_portaudio_h,v 1.2 2013/03/12 00:59:50 brad Exp $
--- include/portaudio.h.orig	2021-04-01 00:35:42 UTC
+++ include/portaudio.h
@@ -287,7 +287,8 @@ typedef enum PaHostApiTypeId
     paWDMKS=11,
     paJACK=12,
     paWASAPI=13,
-    paAudioScienceHPI=14
+    paAudioScienceHPI=14,
+    paSndio=15
 } PaHostApiTypeId;
 
 
@@ -1200,6 +1201,15 @@ signed long Pa_GetStreamReadAvailable( P
 signed long Pa_GetStreamWriteAvailable( PaStream* stream );
 
 
+/** Retrieve the host type handling an open stream.
+
+ @return Returns a non-negative value representing the host API type
+ handling an open stream or, a PaErrorCode (which are always negative)
+ if PortAudio is not initialized or an error is encountered.
+*/
+PaHostApiTypeId Pa_GetStreamHostApiType( PaStream* stream );
+
+
 /* Miscellaneous utilities */
 
 
