--- source/Plugins/SymbolLocator/Default/SymbolLocatorDefault.cpp.orig	2024-12-17 11:04:04 UTC
+++ source/Plugins/SymbolLocator/Default/SymbolLocatorDefault.cpp
@@ -36,7 +36,7 @@
 #include "llvm/Support/FileSystem.h"
 #include "llvm/Support/ThreadPool.h"
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/sysctl.h>
 #endif
 
@@ -145,7 +145,7 @@ std::optional<FileSpec> SymbolLocatorDef
       FileSystem::Instance().Resolve(file_spec);
       debug_file_search_paths.AppendIfUnique(file_spec);
     }
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
     // Add $LOCALBASE/lib/debug directory, where LOCALBASE is
     // usually /usr/local, but may be adjusted by the end user.
     {
