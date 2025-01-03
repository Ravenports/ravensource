$NetBSD: patch-libs_process_src_ext_cwd.cpp,v 1.1 2024/10/10 14:44:17 jperkin Exp $

Spell filesystem correctly.

--- libs/process/src/ext/cwd.cpp.orig	2024-12-05 00:53:35 UTC
+++ libs/process/src/ext/cwd.cpp
@@ -124,7 +124,7 @@ filesystem::path cwd(boost::process::v2:
             filesystem::path("/proc") / std::to_string(pid) / "cwd", ec
             );
 #elif defined(__sun)
-    return fileystem::canonical(
+    return filesystem::canonical(
             filesystem::path("/proc") / std::to_string(pid) / "path/cwd", ec
             );
 #endif
