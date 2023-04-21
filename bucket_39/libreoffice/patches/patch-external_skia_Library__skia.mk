--- external/skia/Library_skia.mk.orig	2023-04-13 18:42:54 UTC
+++ external/skia/Library_skia.mk
@@ -105,6 +105,14 @@ $(eval $(call gb_Library_add_libs,skia,\
 ))
 endif
 
+ifeq ($(OS),FREEBSD)
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
