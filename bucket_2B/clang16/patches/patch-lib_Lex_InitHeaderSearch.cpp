--- lib/Lex/InitHeaderSearch.cpp.orig	2023-06-10 22:58:16 UTC
+++ lib/Lex/InitHeaderSearch.cpp
@@ -392,8 +392,10 @@ void InitHeaderSearch::AddDefaultCPlusPl
       break;
     }
     break;
   case llvm::Triple::DragonFly:
-    AddPath("/usr/include/c++/5.0", CXXSystem, false);
+    AddPath("@RAVEN_GXX_HEADERS_DIR@", CXXSystem, false);
+    AddPath("@RAVEN_GXX_HEADERS_DIR@/backward", CXXSystem, false);
+    AddPath("@RAVEN_GXX_HEADERS_DIR@/" + triple.getTriple(), CXXSystem, false);
     break;
   case llvm::Triple::Minix:
     AddGnuCPlusPlusIncludePaths("/usr/gnu/include/c++/4.4.3",
