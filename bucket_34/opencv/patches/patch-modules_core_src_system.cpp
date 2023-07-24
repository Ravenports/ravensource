--- modules/core/src/system.cpp.orig	2023-06-28 11:53:33 UTC
+++ modules/core/src/system.cpp
@@ -120,7 +120,7 @@ void* allocSingletonNewBuffer(size_t siz
 #include <cstdlib>        // std::abort
 #endif
 
-#if defined __ANDROID__ || defined __unix__ || defined __FreeBSD__ || defined __OpenBSD__ || defined __HAIKU__ || defined __Fuchsia__
+#if defined __ANDROID__ || defined __unix__ || defined __FreeBSD__ || defined __OpenBSD__ || defined __HAIKU__ || defined __Fuchsia__ || defined __DragonFly__ || defined __sun__ || defined __NetBSD__
 #  include <unistd.h>
 #  include <fcntl.h>
 #if defined __QNX__
@@ -245,7 +245,7 @@ std::wstring GetTempFileNameWinRT(std::w
 #include "omp.h"
 #endif
 
-#if defined __unix__ || defined __APPLE__ || defined __EMSCRIPTEN__ || defined __FreeBSD__ || defined __GLIBC__ || defined __HAIKU__
+#if defined __unix__ || defined __APPLE__ || defined __EMSCRIPTEN__ || defined __FreeBSD__ || defined __GLIBC__ || defined __HAIKU__ || defined __DragonFly__ || defined __sun__ || defined __NetBSD__
 #include <unistd.h>
 #include <stdio.h>
 #include <sys/types.h>
