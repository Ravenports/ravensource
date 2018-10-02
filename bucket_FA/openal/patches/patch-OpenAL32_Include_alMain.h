--- OpenAL32/Include/alMain.h.orig	2018-09-06 21:35:18 UTC
+++ OpenAL32/Include/alMain.h
@@ -856,9 +856,6 @@ void ALCcontext_ProcessUpdates(ALCcontex
 
 void AllocateVoices(ALCcontext *context, ALsizei num_voices, ALsizei old_sends);
 
-void AppendAllDevicesList(const ALCchar *name);
-void AppendCaptureDeviceList(const ALCchar *name);
-
 
 extern ALint RTPrioLevel;
 void SetRTPriority(void);
