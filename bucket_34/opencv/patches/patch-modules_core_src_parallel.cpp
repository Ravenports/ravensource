--- modules/core/src/parallel.cpp.orig	2020-10-11 21:26:07 UTC
+++ modules/core/src/parallel.cpp
@@ -55,6 +55,7 @@
 
 #if defined __linux__ || defined __APPLE__ || defined __GLIBC__ \
     || defined __HAIKU__ || defined __EMSCRIPTEN__ || defined __FreeBSD__ \
+    || defined __DragonFly__ \
     || defined __OpenBSD__
     #include <unistd.h>
     #include <stdio.h>
