--- scribus/pdf_analyzer.cpp.orig	2025-06-27 15:47:24 UTC
+++ scribus/pdf_analyzer.cpp
@@ -276,7 +276,7 @@ bool PDFAnalyzer::inspectCanvas(PdfCanva
 	try
 	{
 		// start parsing the content stream
-		PdfContentReaderArgs tokenizerArgs = { PdfContentReaderFlags::DontFollowXObjectForms };
+		PdfContentReaderArgs tokenizerArgs = { PdfContentReaderFlags::SkipFollowFormXObjects };
 		PdfContentStreamReader tokenizer(*canvas, tokenizerArgs);
 		PdfContent pdfContent;
 		PdfVariant var;
