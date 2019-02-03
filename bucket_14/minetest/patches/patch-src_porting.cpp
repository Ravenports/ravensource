--- src/porting.cpp.orig	2018-06-10 15:18:11 UTC
+++ src/porting.cpp
@@ -25,7 +25,7 @@ with this program; if not, write to the
 
 #include "porting.h"
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 	#include <sys/types.h>
 	#include <sys/sysctl.h>
 #elif defined(_WIN32)
