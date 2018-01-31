--- lib/include/libv4l1.h.orig	2013-06-28 20:10:56 UTC
+++ lib/include/libv4l1.h
@@ -25,7 +25,9 @@ extern "C" {
 
 #include <stdio.h>
 #include <stdint.h>
+#ifndef __sun__
 #include <unistd.h>
+#endif
 #include <libv4l1-videodev.h>
 
 #if HAVE_VISIBILITY
