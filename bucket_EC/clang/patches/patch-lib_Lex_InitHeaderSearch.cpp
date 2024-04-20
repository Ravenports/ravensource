--- lib/Lex/InitHeaderSearch.cpp.orig	2024-04-17 00:21:15 UTC
+++ lib/Lex/InitHeaderSearch.cpp
@@ -280,6 +280,11 @@ void InitHeaderSearch::AddDefaultCPlusPl
       break;
     }
     break;
+  case llvm::Triple::DragonFly:
+    AddPath("@RAVEN_GXX_HEADERS_DIR@", CXXSystem, false);
+    AddPath("@RAVEN_GXX_HEADERS_DIR@/backward", CXXSystem, false);
+    AddPath("@RAVEN_GXX_HEADERS_DIR@/" + triple.getTriple(), CXXSystem, false);
+    break;
   default:
     break;
   }
