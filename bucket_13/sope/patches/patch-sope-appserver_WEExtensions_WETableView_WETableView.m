--- sope-appserver/WEExtensions/WETableView/WETableView.m.orig	2026-03-03 11:58:40.000000000 -0000
+++ sope-appserver/WEExtensions/WETableView/WETableView.m
@@ -462,7 +462,7 @@ static inline void _applyState_(WETableV
     infos = [_ctx objectForKey:WETableView_INFOS];
 
     if (infos == nil)
-      infos = [NSArray array];
+      infos = (NSMutableArray *)[NSArray array];
 
     NSAssert(infos != nil, @"Infos is nil.");
 
