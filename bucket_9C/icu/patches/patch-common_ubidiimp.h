$NetBSD: patch-common_ubidiimp.h,v 1.1 2019/04/08 21:39:43 jperkin Exp $

Avoid sys/regset.h pollution on SunOS.

--- common/ubidiimp.h.orig	2020-04-22 20:04:20 UTC
+++ common/ubidiimp.h
@@ -24,6 +24,11 @@
 #include "unicode/uchar.h"
 #include "ubidi_props.h"
 
+#ifdef __sun
+#undef CS
+#undef ES
+#endif
+
 /* miscellaneous definitions ---------------------------------------------- */
 
 typedef uint8_t DirProp;
