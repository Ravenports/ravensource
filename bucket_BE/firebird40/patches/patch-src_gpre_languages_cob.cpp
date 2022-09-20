--- src/gpre/languages/cob.cpp.orig	2022-08-10 09:04:28 UTC
+++ src/gpre/languages/cob.cpp
@@ -60,7 +60,7 @@
 static const char* const COMMIT			= "commit";
 static const char* const ROLLBACK		= "rollback";
 
-#if defined AIX || defined AIX_PPC || defined SOLARIS || defined HP11 || defined LINUX || defined DARWIN || defined FREEBSD || defined NETBSD || defined WIN_NT
+#if defined AIX || defined AIX_PPC || defined SOLARIS || defined HP11 || defined LINUX || defined DARWIN || defined FREEBSD || defined NETBSD || defined WIN_NT || defined DRAGONFLY
 static const char* const OMITTED 		= "BY VALUE 0";
 static const char* const BY_VALUE		= "BY VALUE ";
 static const char* const END_VALUE		= "";
