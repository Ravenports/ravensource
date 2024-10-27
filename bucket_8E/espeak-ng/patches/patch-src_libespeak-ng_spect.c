$NetBSD: patch-src_libespeak-ng_spect.c,v 1.1 2024/03/11 08:03:45 wiz Exp $

Fix endian.h inclusion on NetBSD

--- src/libespeak-ng/spect.c.orig	2022-06-21 14:53:53 UTC
+++ src/libespeak-ng/spect.c
@@ -25,7 +25,12 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+
+#ifdef HAVE_SYS_ENDIAN_H
+#include <sys/endian.h>
+#else
 #include <endian.h>
+#endif
 
 #include <espeak-ng/espeak_ng.h>
 #include <espeak-ng/speak_lib.h>
