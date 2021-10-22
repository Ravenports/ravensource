--- lib/Interpreter/Interpreter.cpp.orig	2021-09-24 16:18:10 UTC
+++ lib/Interpreter/Interpreter.cpp
@@ -47,14 +47,22 @@ GetCC1Arguments(DiagnosticsEngine *Diagn
   // failed. Extract that job from the Compilation.
   const driver::JobList &Jobs = Compilation->getJobs();
   if (!Jobs.size() || !isa<driver::Command>(*Jobs.begin()))
+#if defined __DragonFly__ || defined __NetBSD__
+    return llvm::createStringError(std::errc::operation_not_supported,
+#else
     return llvm::createStringError(std::errc::state_not_recoverable,
+#endif
                                    "Driver initialization failed. "
                                    "Unable to create a driver job");
 
   // The one job we find should be to invoke clang again.
   const driver::Command *Cmd = cast<driver::Command>(&(*Jobs.begin()));
   if (llvm::StringRef(Cmd->getCreator().getName()) != "clang")
+#if defined __DragonFly__ || defined __NetBSD__
+    return llvm::createStringError(std::errc::operation_not_supported,
+#else
     return llvm::createStringError(std::errc::state_not_recoverable,
+#endif
                                    "Driver initialization failed");
 
   return &Cmd->getArguments();
@@ -89,13 +97,21 @@ CreateCI(const llvm::opt::ArgStringList
   // Create the actual diagnostics engine.
   Clang->createDiagnostics();
   if (!Clang->hasDiagnostics())
+#if defined __DragonFly__ || defined __NetBSD__
+    return llvm::createStringError(std::errc::operation_not_supported,
+#else
     return llvm::createStringError(std::errc::state_not_recoverable,
+#endif
                                    "Initialization failed. "
                                    "Unable to create diagnostics engine");
 
   DiagsBuffer->FlushDiagnostics(Clang->getDiagnostics());
   if (!Success)
+#if defined __DragonFly__ || defined __NetBSD__
+    return llvm::createStringError(std::errc::operation_not_supported,
+#else
     return llvm::createStringError(std::errc::state_not_recoverable,
+#endif
                                    "Initialization failed. "
                                    "Unable to flush diagnostics");
 
@@ -106,7 +122,11 @@ CreateCI(const llvm::opt::ArgStringList
   Clang->setTarget(TargetInfo::CreateTargetInfo(
       Clang->getDiagnostics(), Clang->getInvocation().TargetOpts));
   if (!Clang->hasTarget())
+#if defined __DragonFly__ || defined __NetBSD__
+    return llvm::createStringError(std::errc::operation_not_supported,
+#else
     return llvm::createStringError(std::errc::state_not_recoverable,
+#endif
                                    "Initialization failed. "
                                    "Target is missing");
 
