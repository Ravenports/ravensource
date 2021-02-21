Fix build failure with podofo-0.9.7

--- scribus/pdf_analyzer.cpp.orig	2021-02-21 20:19:36 UTC
+++ scribus/pdf_analyzer.cpp
@@ -139,7 +139,9 @@ PDFColorSpace PDFAnalyzer::getCSType(Pdf
 					{
 						pBase = cs->GetOwner()->GetObject(base.GetReference());
 					}
+#if (PODOFO_VERSION < PODOFO_MAKE_VERSION(0, 9, 7))
 					pBase->SetOwner(cs->GetOwner());
+#endif
 					return getCSType(pBase);
 				}
 				if (csTypeName == "Separation")
