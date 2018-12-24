--- modules/core/src/system.cpp.orig	2018-12-21 14:31:20 UTC
+++ modules/core/src/system.cpp
@@ -94,7 +94,7 @@ void* allocSingletonBuffer(size_t size)
 #include <cstdlib>        // std::abort
 #endif
 
-#if defined __ANDROID__ || defined __linux__ || defined __FreeBSD__ || defined __HAIKU__
+#if defined __ANDROID__ || defined __linux__ || defined __FreeBSD__ || defined __HAIKU__ || defined __DragonFly__ || defined __sun__
 #  include <unistd.h>
 #  include <fcntl.h>
 #  include <elf.h>
@@ -202,7 +202,7 @@ std::wstring GetTempFileNameWinRT(std::w
 #include "omp.h"
 #endif
 
-#if defined __linux__ || defined __APPLE__ || defined __EMSCRIPTEN__ || defined __FreeBSD__ || defined __GLIBC__ || defined __HAIKU__
+#if defined __linux__ || defined __APPLE__ || defined __EMSCRIPTEN__ || defined __FreeBSD__ || defined __GLIBC__ || defined __HAIKU__ || defined __DragonFly__ || defined __sun__
 #include <unistd.h>
 #include <stdio.h>
 #include <sys/types.h>
