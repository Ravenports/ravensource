--- sope-appserver/NGObjWeb/WebDAV/SoSubscriptionManager.m.orig	2026-03-03 11:58:40.000000000 -0000
+++ sope-appserver/NGObjWeb/WebDAV/SoSubscriptionManager.m
@@ -186,8 +186,8 @@ static SoSubscriptionManager *sm = nil;
     }
   }
   
-  if (pending  == nil) pending  = [NSArray array];
-  if (inactive == nil) inactive = [NSArray array];
+  if (pending  == nil) pending  = (NSMutableArray *)[NSArray array];
+  if (inactive == nil) inactive = (NSMutableArray *)[NSArray array];
   return [NSDictionary dictionaryWithObjectsAndKeys:
                          pending,  @"pending",
                          inactive, @"inactive",
