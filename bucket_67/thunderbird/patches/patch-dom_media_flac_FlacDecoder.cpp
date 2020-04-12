Enable FLAC on platforms without ffvpx like powerpc*

diff --git dom/media/flac/FlacDecoder.cpp dom/media/flac/FlacDecoder.cpp
index 53fc3c9937f7..b23771ab80fa 100644
--- dom/media/flac/FlacDecoder.cpp.orig	2020-04-07 18:05:03 UTC
+++ dom/media/flac/FlacDecoder.cpp
@@ -7,6 +7,7 @@
 #include "FlacDecoder.h"
 #include "MediaContainerType.h"
 #include "mozilla/StaticPrefs.h"
+#include "PDMFactory.h"
 
 namespace mozilla {
 
@@ -14,6 +15,10 @@ namespace mozilla {
 bool FlacDecoder::IsEnabled() {
 #ifdef MOZ_FFVPX
   return StaticPrefs::MediaFlacEnabled();
+#elif defined(MOZ_FFMPEG)
+  RefPtr<PDMFactory> platform = new PDMFactory();
+  return StaticPrefs::MediaFlacEnabled() && platform->SupportsMimeType(NS_LITERAL_CSTRING("audio/flac"),
+                                    /* DecoderDoctorDiagnostics* */ nullptr);
 #else
   // Until bug 1295886 is fixed.
   return false;
