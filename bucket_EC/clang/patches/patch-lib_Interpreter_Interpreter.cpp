--- lib/Interpreter/Interpreter.cpp.orig	2025-04-16 00:23:49 UTC
+++ lib/Interpreter/Interpreter.cpp
@@ -299,7 +299,11 @@ public:
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
