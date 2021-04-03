--- modules/core/src/parallel.cpp.orig	2021-04-02 11:23:54 UTC
+++ modules/core/src/parallel.cpp
@@ -58,6 +58,7 @@
 
 #if defined __linux__ || defined __APPLE__ || defined __GLIBC__ \
     || defined __HAIKU__ || defined __EMSCRIPTEN__ || defined __FreeBSD__ \
+    || defined __DragonFly__ \
     || defined __OpenBSD__
     #include <unistd.h>
     #include <stdio.h>
