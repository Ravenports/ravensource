--- ogginfo/codec_skeleton.c.orig	2021-01-08 23:13:55 UTC
+++ ogginfo/codec_skeleton.c
@@ -24,6 +24,7 @@
 
 #include <ogg/ogg.h>
 
+#include "utf8.h"
 #include "i18n.h"
 
 #include "private.h"
