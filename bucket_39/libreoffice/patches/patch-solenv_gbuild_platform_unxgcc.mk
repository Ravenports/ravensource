--- solenv/gbuild/platform/unxgcc.mk.orig	2021-04-28 16:17:45 UTC
+++ solenv/gbuild/platform/unxgcc.mk
@@ -52,8 +52,7 @@ endif
 gb_CXXFLAGS := \
 	$(gb_CXXFLAGS_COMMON) \
 	-fPIC \
-	-Wshadow \
-	-Woverloaded-virtual \
+	$(CXXFLAGS_WARN) \
 	$(CXXFLAGS_CXX11) \
 	$(gb_CXX_LINKFLAGS) \
 
