--- lib/Interpreter/IncrementalParser.cpp.orig	2024-06-15 17:21:32 UTC
+++ lib/Interpreter/IncrementalParser.cpp
@@ -126,7 +126,11 @@ public:
           switch (CI.getFrontendOpts().ProgramAction) {
           default:
             Err = llvm::createStringError(
+#if defined __DragonFly__ || defined __NetBSD__
+                std::errc::operation_not_supported,
+#else
                 std::errc::state_not_recoverable,
+#endif
                 "Driver initialization failed. "
                 "Incremental mode for action %d is not supported",
                 CI.getFrontendOpts().ProgramAction);
