--- external/skia/Library_skia.mk.orig	2025-01-23 21:25:49 UTC
+++ external/skia/Library_skia.mk
@@ -118,6 +118,14 @@ $(eval $(call gb_Library_add_libs,skia,\
 ))
 endif
 
+ifneq (,$(filter DRAGONFLY FREEBSD NETBSD,$(OS)))
+$(eval $(call gb_Library_add_libs,skia,\
+    -lm \
+    -lX11-xcb \
+    -lX11 \
+))
+endif
+
 $(eval $(call gb_Library_use_libraries,skia,\
     sal \
 ))
