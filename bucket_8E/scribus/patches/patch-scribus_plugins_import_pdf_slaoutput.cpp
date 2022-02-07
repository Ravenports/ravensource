--- scribus/plugins/import/pdf/slaoutput.cpp.orig	2022-02-07 00:28:49 UTC
+++ scribus/plugins/import/pdf/slaoutput.cpp
@@ -7,6 +7,11 @@ for which a new license (GPL+exception)
 
 #include "slaoutput.h"
 
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 2, 0)
+#include <memory>
+#include <optional>
+#endif
+
 #include <poppler/GlobalParams.h>
 #include <poppler/poppler-config.h>
 #include <poppler/FileSpec.h>
@@ -3027,18 +3032,24 @@ void SlaOutputDev::markPoint(POPPLER_CON
 void SlaOutputDev::updateFont(GfxState *state)
 {
 	GfxFont *gfxFont;
-	GfxFontLoc *fontLoc;
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 2, 0)
+	std::optional<GfxFontLoc> fontLoc;
+	const GooString * fileName = nullptr;
+	std::unique_ptr<FoFiTrueType> ff;
+#else
+	GfxFontLoc * fontLoc = nullptr;
+	GooString * fileName = nullptr;
+	FoFiTrueType * ff = nullptr;
+#endif
 	GfxFontType fontType;
 	SlaOutFontFileID *id;
 	SplashFontFile *fontFile;
 	SplashFontSrc *fontsrc = nullptr;
-	FoFiTrueType *ff;
 	Object refObj, strObj;
-	GooString *fileName;
-	char *tmpBuf;
+	char *tmpBuf = nullptr;
 	int tmpBufLen = 0;
-	int *codeToGID;
-	const double *textMat;
+	int *codeToGID = nullptr;
+	const double *textMat = nullptr;
 	double m11, m12, m21, m22, fontSize;
 	SplashCoord mat[4];
 	int n = 0;
@@ -3046,9 +3057,6 @@ void SlaOutputDev::updateFont(GfxState *
 	SplashCoord matrix[6];
 
 	m_font = nullptr;
-	fileName = nullptr;
-	tmpBuf = nullptr;
-	fontLoc = nullptr;
 
 	gfxFont = state->getFont();
 	if (!gfxFont)
@@ -3064,10 +3072,10 @@ void SlaOutputDev::updateFont(GfxState *
 		delete id;
 	else
 	{
-		if (!(fontLoc = gfxFont->locateFont(xref, nullptr)))
+		fontLoc = gfxFont->locateFont((xref) ? xref : pdfDoc->getXRef(), nullptr);
+		if (!fontLoc)
 		{
-			error(errSyntaxError, -1, "Couldn't find a font for '{0:s}'",
-			gfxFont->getName() ? gfxFont->getName()->getCString() : "(unnamed)");
+			error(errSyntaxError, -1, "Couldn't find a font for '{0:s}'", gfxFont->getName() ? gfxFont->getName()->getCString() : "(unnamed)");
 			goto err2;
 		}
 
@@ -3083,7 +3091,11 @@ void SlaOutputDev::updateFont(GfxState *
 		}
 		else
 		{ // gfxFontLocExternal
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 2, 0)
+			fileName = fontLoc->pathAsGooString();
+#else
 			fileName = fontLoc->path;
+#endif
 			fontType = fontLoc->fontType;
 		}
 
@@ -3136,9 +3148,14 @@ void SlaOutputDev::updateFont(GfxState *
 				ff = FoFiTrueType::make(tmpBuf, tmpBufLen);
 			if (ff)
 			{
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 2, 0)
+				codeToGID = ((Gfx8BitFont*) gfxFont)->getCodeToGIDMap(ff.get());
+				ff.reset();
+#else
 				codeToGID = ((Gfx8BitFont *)gfxFont)->getCodeToGIDMap(ff);
-				n = 256;
 				delete ff;
+#endif
+				n = 256;
 			}
 			else
 			{
@@ -3209,8 +3226,13 @@ void SlaOutputDev::updateFont(GfxState *
 					ff = FoFiTrueType::make(tmpBuf, tmpBufLen);
 				if (! ff)
 					goto err2;
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 2, 0)
+				codeToGID = ((GfxCIDFont*) gfxFont)->getCodeToGIDMap(ff.get(), &n);
+				ff.reset();
+#else
 				codeToGID = ((GfxCIDFont *)gfxFont)->getCodeToGIDMap(ff, &n);
 				delete ff;
+#endif
 			}
 			if (!(fontFile = m_fontEngine->loadTrueTypeFont(
 							id,
@@ -3247,14 +3269,19 @@ void SlaOutputDev::updateFont(GfxState *
 	mat[3] = -m22;
 	m_font = m_fontEngine->getFont(fontFile, mat, matrix);
 
+#if POPPLER_ENCODED_VERSION < POPPLER_VERSION_ENCODE(22, 2, 0)
 	delete fontLoc;
+#endif
 	if (fontsrc && !fontsrc->isFile)
 		fontsrc->unref();
 	return;
 
 err2:
 	delete id;
+#if POPPLER_ENCODED_VERSION < POPPLER_VERSION_ENCODE(22, 2, 0)
 	delete fontLoc;
+#endif
+
 err1:
 	if (fontsrc && !fontsrc->isFile)
 		fontsrc->unref();
