--- modules/core/src/parallel.cpp.orig	2025-07-02 07:54:13 UTC
+++ modules/core/src/parallel.cpp
@@ -58,6 +58,7 @@
 
 #if defined __unix__ || defined __APPLE__ || defined __GLIBC__ \
     || defined __HAIKU__ || defined __EMSCRIPTEN__ \
+    || defined __DragonFly__ \
     || defined __FreeBSD__ || defined __NetBSD__ || defined __OpenBSD__
     #include <unistd.h>
     #include <stdio.h>
