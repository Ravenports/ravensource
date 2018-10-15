--- OpenAL32/alBuffer.c.orig	2018-10-11 22:05:31 UTC
+++ OpenAL32/alBuffer.c
@@ -1118,7 +1118,7 @@ static ALboolean DecomposeUserFormat(ALe
         { AL_FORMAT_BFORMAT3D_FLOAT32, UserFmtBFormat3D, UserFmtFloat },
         { AL_FORMAT_BFORMAT3D_MULAW,   UserFmtBFormat3D, UserFmtMulaw },
     };
-    ALuint i;
+    volatile ALuint i;
 
     for(i = 0;i < COUNTOF(list);i++)
     {
