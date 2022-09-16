--- coreconf/location.mk.orig	2022-06-23 17:41:58 UTC
+++ coreconf/location.mk
@@ -37,7 +37,7 @@ ifdef NSPR_INCLUDE_DIR
 endif
 
 ifndef NSPR_LIB_DIR
-    NSPR_LIB_DIR = $(DIST)/lib
+    NSPR_LIB_DIR = $(PREFIX)/lib
 endif
 
 ifdef NSS_INCLUDE_DIR
