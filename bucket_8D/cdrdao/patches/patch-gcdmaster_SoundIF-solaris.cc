--- gcdmaster/SoundIF-solaris.cc.orig	2023-02-03 14:46:06 UTC
+++ gcdmaster/SoundIF-solaris.cc
@@ -45,6 +45,7 @@
  * Sound interface for Solaris. Thanks to Tobias Oetiker <oetiker@ee.ethz.ch>.
  */
 
+#include <sys/types.h>
 #include <sys/audioio.h>
 #include <stdio.h>
 #include <assert.h>
@@ -196,7 +197,7 @@ int SoundIFImpl::setupDevice()
   auinf.play.sample_rate=44100;
   auinf.play.channels=2;
   auinf.play.precision=16;
-  auinf.play.encoding=AUDIO_ENCODING_LINEAR;
+  auinf.play.encoding=AUDIO_ENCODING_SLINEAR_BE;
 
   if (ioctl(dspFd_, AUDIO_SETINFO, &auinf) < 0) {
     log_message(-1, _("Cannot setup audio interface: %s"), strerror(errno));
