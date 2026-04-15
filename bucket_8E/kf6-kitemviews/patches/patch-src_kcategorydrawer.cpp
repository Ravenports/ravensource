--- src/kcategorydrawer.cpp.orig	2026-03-07 20:31:33 UTC
+++ src/kcategorydrawer.cpp
@@ -78,7 +78,7 @@ void KCategoryDrawer::drawCategory(const
         QRect backgroundRect(option.rect);
         backgroundRect.setLeft(fontMetrics.horizontalAdvance(category) + sidePadding * 2);
         backgroundRect.setRight(backgroundRect.right() - sidePadding);
-        backgroundRect.setTop(backgroundRect.top() + topPadding + ceil(fontMetrics.height() / 2));
+        backgroundRect.setTop(backgroundRect.top() + topPadding + ceil(fontMetrics.height() / 2.0));
         backgroundRect.setHeight(1);
         painter->save();
         painter->setBrush(backgroundColor);
