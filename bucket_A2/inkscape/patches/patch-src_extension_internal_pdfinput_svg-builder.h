--- src/extension/internal/pdfinput/svg-builder.h.orig	2019-01-15 04:29:27 UTC
+++ src/extension/internal/pdfinput/svg-builder.h
@@ -108,7 +108,7 @@ public:
 
     // Path adding
     void addPath(GfxState *state, bool fill, bool stroke, bool even_odd=false);
-    void addShadedFill(GfxShading *shading, double *matrix, GfxPath *path, bool even_odd=false);
+    void addShadedFill(GfxShading *shading, double *matrix, const GfxPath *path, bool even_odd=false);
 
     // Image handling
     void addImage(GfxState *state, Stream *str, int width, int height,
