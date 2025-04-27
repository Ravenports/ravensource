--- source/Plugins/SymbolLocator/Default/SymbolLocatorDefault.cpp.orig	2025-04-16 00:23:49 UTC
+++ source/Plugins/SymbolLocator/Default/SymbolLocatorDefault.cpp
@@ -145,7 +145,7 @@ std::optional<FileSpec> SymbolLocatorDef
       FileSystem::Instance().Resolve(file_spec);
       debug_file_search_paths.AppendIfUnique(file_spec);
     }
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) && !defined(__MidnightBSD__)
     // Add $LOCALBASE/lib/debug directory, where LOCALBASE is
     // usually /usr/local, but may be adjusted by the end user.
     {
