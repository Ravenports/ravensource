--- lib/Interpreter/IncrementalParser.cpp.orig	2021-09-24 16:18:10 UTC
+++ lib/Interpreter/IncrementalParser.cpp
@@ -53,7 +53,11 @@ public:
           switch (CI.getFrontendOpts().ProgramAction) {
           default:
             Err = llvm::createStringError(
+#ifdef __DragonFly__
+                std::errc::operation_not_supported,
+#else
                 std::errc::state_not_recoverable,
+#endif
                 "Driver initialization failed. "
                 "Incremental mode for action %d is not supported",
                 CI.getFrontendOpts().ProgramAction);
