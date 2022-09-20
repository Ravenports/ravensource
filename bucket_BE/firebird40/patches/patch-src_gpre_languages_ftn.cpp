--- src/gpre/languages/ftn.cpp.orig	2022-08-10 09:04:28 UTC
+++ src/gpre/languages/ftn.cpp
@@ -225,7 +225,7 @@ const char* const I4CONST_2			= "";
 const char* const COMMENT			= "*     ";
 const char* const INLINE_COMMENT	= "\n*                ";
 const char* const COMMA				= ",";
-#elif (defined FREEBSD || defined NETBSD)
+#elif (defined FREEBSD || defined NETBSD || defined DRAGONFLY)
 const char* const INCLUDE_ISC_FTN	= "       INCLUDE  \'%s\' \n\n";
 const char* const INCLUDE_FTN_FILE	= "gds.f";
 const char* const DOUBLE_DCL		= "DOUBLE PRECISION";
