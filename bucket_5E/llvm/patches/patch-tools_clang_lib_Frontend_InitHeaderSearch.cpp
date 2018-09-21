--- tools/clang/lib/Frontend/InitHeaderSearch.cpp.orig	2018-06-28 23:23:45 UTC
+++ tools/clang/lib/Frontend/InitHeaderSearch.cpp
@@ -429,7 +429,9 @@ void InitHeaderSearch::AddDefaultCPlusPl
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
