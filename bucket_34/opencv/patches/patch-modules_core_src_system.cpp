--- modules/core/src/system.cpp.orig	2018-07-04 11:05:47 UTC
+++ modules/core/src/system.cpp
@@ -91,7 +91,7 @@ static bool param_dumpErrors = utils::ge
 #include <cstdlib>        // std::abort
 #endif
 
-#if defined __ANDROID__ || defined __linux__ || defined __FreeBSD__ || defined __HAIKU__
+#if defined __ANDROID__ || defined __linux__ || defined __FreeBSD__ || defined __HAIKU__ || defined __DragonFly__ || defined __sun__
 #  include <unistd.h>
 #  include <fcntl.h>
 #  include <elf.h>
@@ -200,7 +200,7 @@ std::wstring GetTempFileNameWinRT(std::w
 #include "omp.h"
 #endif
 
-#if defined __linux__ || defined __APPLE__ || defined __EMSCRIPTEN__ || defined __FreeBSD__ || defined __GLIBC__ || defined __HAIKU__
+#if defined __linux__ || defined __APPLE__ || defined __EMSCRIPTEN__ || defined __FreeBSD__ || defined __GLIBC__ || defined __HAIKU__ || defined __DragonFly__ || defined __sun__
 #include <unistd.h>
 #include <stdio.h>
 #include <sys/types.h>
