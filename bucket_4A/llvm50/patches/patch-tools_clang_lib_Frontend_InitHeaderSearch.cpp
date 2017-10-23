--- tools/clang/lib/Frontend/InitHeaderSearch.cpp.orig	2017-06-03 06:27:16 UTC
+++ tools/clang/lib/Frontend/InitHeaderSearch.cpp
@@ -413,7 +413,9 @@ AddDefaultCPlusPlusIncludePaths(const ll
     }
     break;
   case llvm::Triple::DragonFly:
-    AddPath("/usr/include/c++/5.0", CXXSystem, false);
+    AddPath("@RAVEN_GXX_HEADERS_DIR@", CXXSystem, false);
+    AddPath("@RAVEN_GXX_HEADERS_DIR@/backward", CXXSystem, false);
+    AddPath("@RAVEN_GXX_HEADERS_DIR@/" + triple.getTriple(), CXXSystem, false);
     break;
   case llvm::Triple::OpenBSD: {
     std::string t = triple.getTriple();
