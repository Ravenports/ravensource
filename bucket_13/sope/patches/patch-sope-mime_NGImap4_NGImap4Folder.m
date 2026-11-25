--- sope-mime/NGImap4/NGImap4Folder.m.orig	2026-11-21 06:01:41 UTC
+++ sope-mime/NGImap4/NGImap4Folder.m
@@ -300,7 +300,7 @@ static int FetchNewUnseenMessagesInSubFo
   msn  = [[dict objectForKey:@"search"] mutableCopy];
   
   if ((msn == nil) || ![msn isNotEmpty]) {
-    mes = [NSArray array];
+    mes = (NSMutableArray *)[NSArray array];
   }
   else {
     NSEnumerator *seq = nil;
