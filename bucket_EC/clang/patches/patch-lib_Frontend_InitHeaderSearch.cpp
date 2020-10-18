--- lib/Frontend/InitHeaderSearch.cpp.orig	2020-10-07 10:10:48 UTC
+++ lib/Frontend/InitHeaderSearch.cpp
@@ -222,7 +222,6 @@ void InitHeaderSearch::AddDefaultCInclud
   if (HSOpts.UseStandardSystemIncludes) {
     switch (os) {
     case llvm::Triple::CloudABI:
-    case llvm::Triple::FreeBSD:
     case llvm::Triple::NetBSD:
     case llvm::Triple::OpenBSD:
     case llvm::Triple::NaCl:
@@ -398,8 +397,15 @@ void InitHeaderSearch::AddDefaultCPlusPl
       break;
     }
     break;
+  case llvm::Triple::FreeBSD:
+    AddPath("@RAVEN_GXX_HEADERS_DIR@", CXXSystem, false);
+    AddPath("@RAVEN_GXX_HEADERS_DIR@/backward", CXXSystem, false);
+    AddPath("@RAVEN_GXX_HEADERS_DIR@/" + triple.getTriple(), CXXSystem, false);
+    break;
   case llvm::Triple::DragonFly:
-    AddPath("/usr/include/c++/5.0", CXXSystem, false);
+    AddPath("@RAVEN_GXX_HEADERS_DIR@", CXXSystem, false);
+    AddPath("@RAVEN_GXX_HEADERS_DIR@/backward", CXXSystem, false);
+    AddPath("@RAVEN_GXX_HEADERS_DIR@/" + triple.getTriple(), CXXSystem, false);
     break;
   case llvm::Triple::Minix:
     AddGnuCPlusPlusIncludePaths("/usr/gnu/include/c++/4.4.3",
