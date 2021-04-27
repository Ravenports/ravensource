--- Source/JavaScriptCore/runtime/IntlSegments.cpp.orig	2021-02-26 09:57:05 UTC
+++ Source/JavaScriptCore/runtime/IntlSegments.cpp
@@ -100,7 +100,7 @@ JSObject* IntlSegments::createSegmentIte
     auto scope = DECLARE_THROW_SCOPE(vm);
 
     UErrorCode status = U_ZERO_ERROR;
-    auto segmenter = std::unique_ptr<UBreakIterator, UBreakIteratorDeleter>(ubrk_safeClone(m_segmenter.get(), nullptr, nullptr, &status));
+    auto segmenter = std::unique_ptr<UBreakIterator, UBreakIteratorDeleter>(ubrk_clone(m_segmenter.get(), &status));
     if (U_FAILURE(status)) {
         throwTypeError(globalObject, scope, "failed to initialize SegmentIterator"_s);
         return nullptr;
