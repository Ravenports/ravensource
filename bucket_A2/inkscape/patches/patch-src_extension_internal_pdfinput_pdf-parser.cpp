--- src/extension/internal/pdfinput/pdf-parser.cpp.orig	2019-01-15 04:29:27 UTC
+++ src/extension/internal/pdfinput/pdf-parser.cpp
@@ -426,7 +426,7 @@ void PdfParser::parse(Object *obj, GBool
 	error(errInternal, -1, "Weird page contents");
     	return;
   }
-  parser = new Parser(xref, new Lexer(xref, obj), gFalse);
+  parser = new _POPPLER_NEW_PARSER(xref, obj);
   go(topLevel);
   delete parser;
   parser = NULL;
@@ -2414,7 +2414,11 @@ void PdfParser::doShowText(GooString *s)
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
@@ -2537,7 +2541,7 @@ void PdfParser::doShowText(GooString *s)
       originY *= state->getFontSize();
       state->textTransformDelta(originX, originY, &tOriginX, &tOriginY);
       builder->addChar(state, state->getCurX() + riseX, state->getCurY() + riseY,
-                       dx, dy, tOriginX, tOriginY, code, n, u, uLen);
+                       dx, dy, tOriginX, tOriginY, code, n, (Unicode *)u, uLen);
       state->shift(tdx, tdy);
       p += n;
       len -= n;
