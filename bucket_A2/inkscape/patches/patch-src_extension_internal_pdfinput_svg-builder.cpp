--- src/extension/internal/pdfinput/svg-builder.cpp.orig	2019-01-15 04:29:27 UTC
+++ src/extension/internal/pdfinput/svg-builder.cpp
@@ -264,10 +264,10 @@ static void svgSetTransform(Inkscape::XM
 /**
  * \brief Generates a SVG path string from poppler's data structure
  */
-static gchar *svgInterpretPath(GfxPath *path) {
+static gchar *svgInterpretPath(const GfxPath *path) {
     Inkscape::SVG::PathString pathString;
     for (int i = 0 ; i < path->getNumSubpaths() ; ++i ) {
-        GfxSubpath *subpath = path->getSubpath(i);
+        const GfxSubpath *subpath = path->getSubpath(i);
         if (subpath->getNumPoints() > 0) {
             pathString.moveTo(subpath->getX(0), subpath->getY(0));
             int j = 1;
@@ -458,7 +458,7 @@ void SvgBuilder::addPath(GfxState *state
  * \brief Emits the current path in poppler's GfxState data structure
  * The path is set to be filled with the given shading.
  */
-void SvgBuilder::addShadedFill(GfxShading *shading, double *matrix, GfxPath *path,
+void SvgBuilder::addShadedFill(GfxShading *shading, double *matrix, const GfxPath *path,
                                bool even_odd) {
 
     Inkscape::XML::Node *path_node = _xml_doc->createElement("svg:path");
