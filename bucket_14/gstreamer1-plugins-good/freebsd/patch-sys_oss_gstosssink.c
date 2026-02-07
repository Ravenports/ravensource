--- sys/oss/gstosssink.c.orig	2026-01-27 17:02:33 UTC
+++ sys/oss/gstosssink.c
@@ -107,7 +107,10 @@ enum
   PROP_DEVICE,
 };
 
-#define FORMATS "{" GST_AUDIO_NE(S16)","GST_AUDIO_NE(U16)", S8, U8 }"
+#define FORMATS "{" GST_AUDIO_NE(S32)","GST_AUDIO_NE(U32)"," \
+                    GST_AUDIO_NE(S24)","GST_AUDIO_NE(U24)"," \
+                    GST_AUDIO_NE(S16)","GST_AUDIO_NE(U16)"," \
+                    "S8, U8 }"
 
 static GstStaticPadTemplate osssink_sink_factory =
     GST_STATIC_PAD_TEMPLATE ("sink",
@@ -324,6 +327,9 @@ gst_oss_sink_get_format (GstAudioRingBuf
     case GST_AUDIO_RING_BUFFER_FORMAT_TYPE_RAW:
     {
       switch (rfmt) {
+        case GST_AUDIO_FORMAT_S8:
+          result = AFMT_S8;
+          break;
         case GST_AUDIO_FORMAT_U8:
           result = AFMT_U8;
           break;
@@ -333,15 +339,36 @@ gst_oss_sink_get_format (GstAudioRingBuf
         case GST_AUDIO_FORMAT_S16BE:
           result = AFMT_S16_BE;
           break;
-        case GST_AUDIO_FORMAT_S8:
-          result = AFMT_S8;
-          break;
         case GST_AUDIO_FORMAT_U16LE:
           result = AFMT_U16_LE;
           break;
         case GST_AUDIO_FORMAT_U16BE:
           result = AFMT_U16_BE;
           break;
+        case GST_AUDIO_FORMAT_S24LE:
+          result = AFMT_S24_LE;
+          break;
+        case GST_AUDIO_FORMAT_S24BE:
+          result = AFMT_S24_BE;
+          break;
+        case GST_AUDIO_FORMAT_U24LE:
+          result = AFMT_U24_LE;
+          break;
+        case GST_AUDIO_FORMAT_U24BE:
+          result = AFMT_U24_BE;
+          break;
+        case GST_AUDIO_FORMAT_S32LE:
+          result = AFMT_S32_LE;
+          break;
+        case GST_AUDIO_FORMAT_S32BE:
+          result = AFMT_S32_BE;
+          break;
+        case GST_AUDIO_FORMAT_U32LE:
+          result = AFMT_U32_LE;
+          break;
+        case GST_AUDIO_FORMAT_U32BE:
+          result = AFMT_U32_BE;
+          break;
         default:
           result = 0;
           break;
@@ -444,7 +471,7 @@ gst_oss_sink_prepare (GstAudioSink * asi
   rate = GST_AUDIO_INFO_RATE (&spec->info);
   channels = GST_AUDIO_INFO_CHANNELS (&spec->info);
 
-  if (width != 16 && width != 8)
+  if (width != 32 && width != 24 && width != 16 && width != 8)
     goto dodgy_width;
 
   SET_PARAM (oss, SNDCTL_DSP_SETFMT, tmp, "SETFMT");
