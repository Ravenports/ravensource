--- modules/core/src/system.cpp.orig	2020-04-03 11:45:28 UTC
+++ modules/core/src/system.cpp
@@ -114,7 +114,7 @@ void* allocSingletonNewBuffer(size_t siz
 #include <cstdlib>        // std::abort
 #endif
 
-#if defined __ANDROID__ || defined __linux__ || defined __FreeBSD__ || defined __OpenBSD__ || defined __HAIKU__ || defined __Fuchsia__
+#if defined __ANDROID__ || defined __linux__ || defined __FreeBSD__ || defined __OpenBSD__ || defined __HAIKU__ || defined __Fuchsia__ || defined__DragonFly__ || defined __sun__
 #  include <unistd.h>
 #  include <fcntl.h>
 #  include <elf.h>
@@ -226,7 +226,7 @@ std::wstring GetTempFileNameWinRT(std::w
 #include "omp.h"
 #endif
 
-#if defined __linux__ || defined __APPLE__ || defined __EMSCRIPTEN__ || defined __FreeBSD__ || defined __GLIBC__ || defined __HAIKU__
+#if defined __linux__ || defined __APPLE__ || defined __EMSCRIPTEN__ || defined __FreeBSD__ || defined __GLIBC__ || defined __HAIKU__ || defined __DragonFly__ || defined __sun__
 #include <unistd.h>
 #include <stdio.h>
 #include <sys/types.h>
