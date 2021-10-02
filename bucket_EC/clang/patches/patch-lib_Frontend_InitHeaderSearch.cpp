--- lib/Frontend/InitHeaderSearch.cpp.orig	2021-09-24 16:18:10 UTC
+++ lib/Frontend/InitHeaderSearch.cpp
@@ -226,7 +226,6 @@ void InitHeaderSearch::AddDefaultCInclud
   if (HSOpts.UseStandardSystemIncludes) {
     switch (os) {
     case llvm::Triple::CloudABI:
-    case llvm::Triple::FreeBSD:
     case llvm::Triple::NetBSD:
     case llvm::Triple::OpenBSD:
     case llvm::Triple::NaCl:
@@ -402,8 +401,15 @@ void InitHeaderSearch::AddDefaultCPlusPl
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
