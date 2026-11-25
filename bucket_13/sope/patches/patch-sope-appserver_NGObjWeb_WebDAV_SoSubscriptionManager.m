--- sope-appserver/NGObjWeb/WebDAV/SoSubscriptionManager.m.orig	2026-11-21 06:01:41 UTC
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
