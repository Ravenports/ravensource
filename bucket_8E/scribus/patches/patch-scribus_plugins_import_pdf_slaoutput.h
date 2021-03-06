--- scribus/plugins/import/pdf/slaoutput.h.orig	2021-03-06 05:43:38 UTC
+++ scribus/plugins/import/pdf/slaoutput.h
@@ -196,8 +196,8 @@ public:
 	void stroke(GfxState *state) override;
 	void fill(GfxState *state) override;
 	void eoFill(GfxState *state) override;
-	GBool tilingPatternFill(GfxState *state, Gfx *gfx, Catalog *cat, Object *str, POPPLER_CONST_070 double *pmat, int paintType, int tilingType, Dict *resDict, POPPLER_CONST_070 double *mat, POPPLER_CONST_070 double *bbox, int x0, int y0, int x1, int y1, double xStep, double yStep) override;
-	GBool functionShadedFill(GfxState * /*state*/, GfxFunctionShading * /*shading*/) override { qDebug() << "Function Shaded Fill";  return gFalse; }
+	GBool tilingPatternFill(GfxState *state, Gfx *gfx, Catalog *cat, Object *str, POPPLER_CONST_070 double *pmat, int paintType, int tilingType, Dict *resDict, POPPLER_CONST_070 double *mat, POPPLER_CONST_070 double *bbox, int x0, int y0, int x1, int y1, double xStep, double yStep);
+	GBool functionShadedFill(GfxState * /*state*/, GfxFunctionShading * /*shading*/) { qDebug() << "Function Shaded Fill";  return gFalse; }
 	GBool axialShadedFill(GfxState *state, GfxAxialShading *shading, double tMin, double tMax) override;
 	GBool axialShadedSupportExtend(GfxState *state, GfxAxialShading *shading)  override { return (shading->getExtend0() == shading->getExtend1()); }
 	GBool radialShadedFill(GfxState *state, GfxRadialShading *shading, double sMin, double sMax) override;
