DragonFly actually doesn't support fopencookie

--- Source/storm/storm_file_wrapper.h.orig	2021-11-06 20:46:34 UTC
+++ Source/storm/storm_file_wrapper.h
@@ -1,6 +1,6 @@
 /** A pointer to a Storm file as a `FILE *`. Only available on some platforms. */
 #pragma once
-#if (defined(__linux__) && !defined(__ANDROID__)) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__HAIKU__)
+#if (defined(__linux__) && !defined(__ANDROID__)) || defined(__FreeBSD__) || defined(__HAIKU__)
 #include <cstdio>
 
 #include "storm/storm_sdl_rw.h"
