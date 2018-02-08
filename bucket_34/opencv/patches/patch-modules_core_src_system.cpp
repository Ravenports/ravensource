--- modules/core/src/system.cpp.orig	2017-12-22 19:46:21 UTC
+++ modules/core/src/system.cpp
@@ -67,7 +67,7 @@ Mutex* __initialization_mutex_initialize
 # endif
 #endif
 
-#if defined __ANDROID__ || defined __linux__ || defined __FreeBSD__ || defined __HAIKU__
+#if defined __ANDROID__ || defined __linux__ || defined __FreeBSD__ || defined __HAIKU__ || defined __DragonFly__ || defined __sun__
 #  include <unistd.h>
 #  include <fcntl.h>
 #  include <elf.h>
@@ -215,7 +215,7 @@ std::wstring GetTempFileNameWinRT(std::w
 #include "omp.h"
 #endif
 
-#if defined __linux__ || defined __APPLE__ || defined __EMSCRIPTEN__ || defined __FreeBSD__ || defined __GLIBC__ || defined __HAIKU__
+#if defined __linux__ || defined __APPLE__ || defined __EMSCRIPTEN__ || defined __FreeBSD__ || defined __GLIBC__ || defined __HAIKU__ || defined __DragonFly__ || defined __sun__
 #include <unistd.h>
 #include <stdio.h>
 #include <sys/types.h>
