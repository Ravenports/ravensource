--- solenv/gbuild/platform/unxgcc.mk.orig	2019-04-10 10:10:51 UTC
+++ solenv/gbuild/platform/unxgcc.mk
@@ -45,8 +45,7 @@ gb_CFLAGS := \
 gb_CXXFLAGS := \
 	$(gb_CXXFLAGS_COMMON) \
 	-fPIC \
-	-Wshadow \
-	-Woverloaded-virtual \
+	$(CXXFLAGS_WARN) \
 	$(CXXFLAGS_CXX11) \
 
 
