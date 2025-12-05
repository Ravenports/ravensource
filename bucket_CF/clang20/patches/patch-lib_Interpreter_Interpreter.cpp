--- lib/Interpreter/Interpreter.cpp.orig	2025-06-13 04:54:32 UTC
+++ lib/Interpreter/Interpreter.cpp
@@ -300,7 +300,11 @@ public:
           switch (CI.getFrontendOpts().ProgramAction) {
           default:
             Err = llvm::createStringError(
+#if defined __DragonFly__ || defined __NetBSD__
+		std::errc::operation_not_supported,
+#else
                 std::errc::state_not_recoverable,
+#endif
                 "Driver initialization failed. "
                 "Incremental mode for action %d is not supported",
                 CI.getFrontendOpts().ProgramAction);
