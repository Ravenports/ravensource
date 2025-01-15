--- solenv/gbuild/platform/unxgcc.mk.orig	2025-01-12 19:04:12 UTC
+++ solenv/gbuild/platform/unxgcc.mk
@@ -55,8 +55,7 @@ endif
 gb_CXXFLAGS := \
 	$(gb_CXXFLAGS_COMMON) \
 	-fPIC \
-	-Wshadow \
-	-Woverloaded-virtual \
+	$(CXXFLAGS_WARN) \
 	$(CXXFLAGS_CXX11) \
 	$(gb_CXX_LINKFLAGS) \
 
