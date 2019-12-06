--- src/extension/internal/pdfinput/pdf-parser.cpp.orig	2019-01-15 04:29:27 UTC
+++ src/extension/internal/pdfinput/pdf-parser.cpp
@@ -272,7 +272,11 @@ public:
     ClipHistoryEntry *save();
     ClipHistoryEntry *restore();
     GBool hasSaves() { return saved != NULL; }
+#if POPPLER_CHECK_VERSION(0,83,0)
+    void setClip(const GfxPath *newClipPath, GfxClipType newClipType = clipNormal);
+#else
     void setClip(GfxPath *newClipPath, GfxClipType newClipType = clipNormal);
+#endif
     GfxPath *getClipPath() { return clipPath; }
     GfxClipType getClipType() { return clipType; }
 
@@ -426,7 +430,7 @@ void PdfParser::parse(Object *obj, GBool
 	error(errInternal, -1, "Weird page contents");
     	return;
   }
-  parser = new Parser(xref, new Lexer(xref, obj), gFalse);
+  parser = new _POPPLER_NEW_PARSER(xref, obj);
   go(topLevel);
   delete parser;
   parser = NULL;
@@ -2414,7 +2418,11 @@ void PdfParser::doShowText(GooString *s)
   int wMode;
   double riseX, riseY;
   CharCode code;
+#if POPPLER_CHECK_VERSION(0,82,0)
+  const Unicode *u = NULL;
+#else
   Unicode *u = NULL;
+#endif
   double x, y, dx, dy, tdx, tdy;
   double originX, originY, tOriginX, tOriginY;
   double oldCTM[6], newCTM[6];
@@ -2537,7 +2545,7 @@ void PdfParser::doShowText(GooString *s)
       originY *= state->getFontSize();
       state->textTransformDelta(originX, originY, &tOriginX, &tOriginY);
       builder->addChar(state, state->getCurX() + riseX, state->getCurY() + riseY,
-                       dx, dy, tOriginX, tOriginY, code, n, u, uLen);
+                       dx, dy, tOriginX, tOriginY, code, n, (Unicode *)u, uLen);
       state->shift(tdx, tdy);
       p += n;
       len -= n;
@@ -3394,7 +3402,11 @@ ClipHistoryEntry::~ClipHistoryEntry()
     }
 }
 
+#if POPPLER_CHECK_VERSION(0,83,0)
+void ClipHistoryEntry::setClip(const GfxPath *clipPathA, GfxClipType clipTypeA) {
+#else
 void ClipHistoryEntry::setClip(GfxPath *clipPathA, GfxClipType clipTypeA) {
+#endif
     // Free previous clip path
     if (clipPath) {
         delete clipPath;
