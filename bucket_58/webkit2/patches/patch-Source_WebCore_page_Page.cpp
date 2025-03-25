--- Source/WebCore/page/Page.cpp.orig	2025-03-11 09:29:45 UTC
+++ Source/WebCore/page/Page.cpp
@@ -539,8 +539,10 @@ Page::~Page()
     if (RefPtr scrollingCoordinator = m_scrollingCoordinator)
         scrollingCoordinator->pageDestroyed();
 
+#if ENABLE(RESOURCE_USAGE)
     if (RefPtr resourceUsageOverlay = m_resourceUsageOverlay)
         resourceUsageOverlay->detachFromPage();
+#endif
 
     checkedBackForward()->close();
     if (!isUtilityPage())
