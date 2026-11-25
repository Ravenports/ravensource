--- src/ipa/ipa/bmp.h.orig	2026-10-16 14:52:52 UTC
+++ src/ipa/ipa/bmp.h
@@ -17,6 +17,7 @@
    Boston, MA 02111-1307, USA.  */
 
 
+#include <stdint.h>
 #ifndef HAVE_GD
 /* png stuff below adapted from stuff sent to me [fjf] by Lennard D. Rosenthal;
  * probably used in ImageMagick and may not be covered, therefore, by the LGPL - (fjf)
