--- solenv/gbuild/platform/unxgcc.mk.orig	2018-10-30 16:55:21 UTC
+++ solenv/gbuild/platform/unxgcc.mk
@@ -45,8 +45,7 @@ gb_CFLAGS := \
 gb_CXXFLAGS := \
 	$(gb_CXXFLAGS_COMMON) \
 	-fPIC \
-	-Wshadow \
-	-Woverloaded-virtual \
+	$(CXXFLAGS_WARN) \
 	$(CXXFLAGS_CXX11) \
 
 
