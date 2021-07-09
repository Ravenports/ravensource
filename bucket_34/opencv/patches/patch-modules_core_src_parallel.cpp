--- modules/core/src/parallel.cpp.orig	2021-07-05 12:03:22 UTC
+++ modules/core/src/parallel.cpp
@@ -58,6 +58,7 @@
 
 #if defined __linux__ || defined __APPLE__ || defined __GLIBC__ \
     || defined __HAIKU__ || defined __EMSCRIPTEN__ || defined __FreeBSD__ \
+    || defined __DragonFly__ \
     || defined __OpenBSD__
     #include <unistd.h>
     #include <stdio.h>
