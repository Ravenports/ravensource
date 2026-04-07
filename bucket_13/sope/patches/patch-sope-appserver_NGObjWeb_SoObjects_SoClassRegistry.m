--- sope-appserver/NGObjWeb/SoObjects/SoClassRegistry.m.orig	2026-03-03 11:58:39.000000000 -0000
+++ sope-appserver/NGObjWeb/SoObjects/SoClassRegistry.m
@@ -126,7 +126,7 @@ static SoClassRegistry *registry = nil;
   
   if (_clazz == Nil)
     return nil;
-  if ((soClass = [self->objcToSoClass objectForKey:_clazz]))
+  if ((soClass = [self->objcToSoClass objectForKey:(id)_clazz]))
     return soClass;
   
   soSuper = [self soClassForClass:[_clazz superclass]];
@@ -136,7 +136,7 @@ static SoClassRegistry *registry = nil;
     [self debugWithFormat:@"could not create SoClass for class %@ !", _clazz];
     return nil;
   }
-  [self->objcToSoClass setObject:soClass forKey:_clazz];
+  [self->objcToSoClass setObject:soClass forKey:(id)_clazz];
   [soClass rescanClass];
   [self debugWithFormat:@"mapped class %@ to SoClass %@", 
 	  NSStringFromClass(_clazz), soClass];
