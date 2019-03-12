--- solenv/gbuild/platform/unxgcc.mk.orig	2019-01-23 19:35:25 UTC
+++ solenv/gbuild/platform/unxgcc.mk
@@ -45,8 +45,7 @@ gb_CFLAGS := \
 gb_CXXFLAGS := \
 	$(gb_CXXFLAGS_COMMON) \
 	-fPIC \
-	-Wshadow \
-	-Woverloaded-virtual \
+	$(CXXFLAGS_WARN) \
 	$(CXXFLAGS_CXX11) \
 
 
