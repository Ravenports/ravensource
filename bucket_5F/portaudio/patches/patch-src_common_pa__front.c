--- src/common/pa_front.c.orig	2016-10-30 01:23:04 UTC
+++ src/common/pa_front.c
@@ -1257,8 +1257,10 @@ PaError Pa_OpenStream( PaStream** stream
                                   hostApiInputParametersPtr, hostApiOutputParametersPtr,
                                   sampleRate, framesPerBuffer, streamFlags, streamCallback, userData );
 
-    if( result == paNoError )
+    if( result == paNoError ) {
         AddOpenStream( *stream );
+        PA_STREAM_REP(*stream)->hostApiType = hostApi->info.type;
+    }
 
 
     PA_LOGAPI(("Pa_OpenStream returned:\n" ));
@@ -1770,6 +1772,32 @@ signed long Pa_GetStreamWriteAvailable(
     return result;
 }
 
+PaHostApiTypeId Pa_GetStreamHostApiType( PaStream* stream )
+{
+    PaError error = PaUtil_ValidateStreamPointer( stream );
+    PaHostApiTypeId result;
+
+#ifdef PA_LOG_API_CALLS
+    PaUtil_DebugPrint("Pa_GetStreamHostApiType called:\n" );
+    PaUtil_DebugPrint("\tPaStream* stream: 0x%p\n", stream );
+#endif
+
+    if( error == paNoError )
+    {
+        result = PA_STREAM_REP(stream)->hostApiType;
+    }
+    else
+    {
+        result = (PaHostApiTypeId) error;
+    }
+
+#ifdef PA_LOG_API_CALLS
+    PaUtil_DebugPrint("Pa_GetStreamHostApiType returned:\n" );
+    PaUtil_DebugPrint("\tPaError: %d ( %s )\n\n", result, Pa_GetErrorText( result ) );
+#endif
+
+    return result;
+}
 
 PaError Pa_GetSampleSize( PaSampleFormat format )
 {
