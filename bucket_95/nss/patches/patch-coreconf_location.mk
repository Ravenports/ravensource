--- coreconf/location.mk.orig	2025-12-05 03:57:44 UTC
+++ coreconf/location.mk
@@ -37,7 +37,7 @@ ifdef NSPR_INCLUDE_DIR
 endif
 
 ifndef NSPR_LIB_DIR
-    NSPR_LIB_DIR = $(DIST)/lib
+    NSPR_LIB_DIR = $(PREFIX)/lib
 endif
 
 ifdef NSS_INCLUDE_DIR
