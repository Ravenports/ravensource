--- coreconf/location.mk.orig	2019-01-23 08:35:38 UTC
+++ coreconf/location.mk
@@ -40,7 +40,7 @@ ifdef NSPR_INCLUDE_DIR
 endif
 
 ifndef NSPR_LIB_DIR
-    NSPR_LIB_DIR = $(DIST)/lib
+    NSPR_LIB_DIR = $(PREFIX)/lib
 endif
 
 ifdef NSS_INCLUDE_DIR
