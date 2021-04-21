Fix build with llvm 12.0

--- src/gallium/frontends/clover/llvm/invocation.cpp.orig	2021-04-21 17:41:10 UTC
+++ src/gallium/frontends/clover/llvm/invocation.cpp
@@ -249,7 +249,7 @@ namespace {
 
       c->getInvocation().setLangDefaults(c->getLangOpts(),
                                 compat::ik_opencl, ::llvm::Triple(target.triple),
-                                c->getPreprocessorOpts(),
+                                c->getPreprocessorOpts().Includes,
                                 get_language_version(opts, device_clc_version));
 
       c->createDiagnostics(new clang::TextDiagnosticPrinter(
