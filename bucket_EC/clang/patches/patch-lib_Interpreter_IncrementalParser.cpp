--- lib/Interpreter/IncrementalParser.cpp.orig	2024-10-15 08:17:37 UTC
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
