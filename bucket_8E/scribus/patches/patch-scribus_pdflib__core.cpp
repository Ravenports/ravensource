--- scribus/pdflib_core.cpp.orig	2025-06-27 15:47:24 UTC
+++ scribus/pdflib_core.cpp
@@ -9856,7 +9856,7 @@ bool PDFLibCore::PDF_EmbeddedPDF(PageIte
 			writer.startObj(xObj);
 			PutDoc("<<\n/Type /XObject\n/Subtype /Form\n/FormType 1");
 			PoDoFo::Rect pageRect = page.GetArtBox(true); // Because scimagedataloader_pdf use ArtBox
-			int rotation = page.GetRotationRaw();
+			unsigned rotation = page.GetRotation();
 			double imgWidth  = (rotation == 90 || rotation == 270) ? pageRect.Height : pageRect.Width;
 			double imgHeight = (rotation == 90 || rotation == 270) ? pageRect.Width : pageRect.Height;
 			QTransform pageM;
@@ -9977,7 +9977,7 @@ bool PDFLibCore::PDF_EmbeddedPDF(PageIte
 			writer.startObj(xObj);
 			PutDoc("<<\n/Type /XObject\n/Subtype /Form\n/FormType 1");
 			PoDoFo::Rect pageRect = page.GetArtBox(true); // Because scimagedataloader_pdf use ArtBox
-			int rotation = page.GetRotationRaw();
+			unsigned rotation = page.GetRotation();
 			double imgWidth  = (rotation == 90 || rotation == 270) ? pageRect.Height : pageRect.Width;
 			double imgHeight = (rotation == 90 || rotation == 270) ? pageRect.Width : pageRect.Height;
 			QTransform pageM;
