--- solenv/gbuild/platform/unxgcc.mk.orig	2018-02-08 14:35:19 UTC
+++ solenv/gbuild/platform/unxgcc.mk
@@ -45,8 +45,7 @@ gb_CFLAGS := \
 gb_CXXFLAGS := \
 	$(gb_CXXFLAGS_COMMON) \
 	-fPIC \
-	-Wshadow \
-	-Woverloaded-virtual \
+	$(CXXFLAGS_WARN) \
 	$(CXXFLAGS_CXX11) \
 
 
