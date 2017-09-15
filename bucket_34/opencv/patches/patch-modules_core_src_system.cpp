--- modules/core/src/system.cpp.orig	2017-08-03 23:58:23 UTC
+++ modules/core/src/system.cpp
@@ -66,7 +66,7 @@ Mutex* __initialization_mutex_initialize
 # endif
 #endif
 
-#if defined __ANDROID__ || defined __linux__ || defined __FreeBSD__
+#if defined __ANDROID__ || defined __linux__ || defined __FreeBSD__ || defined __DragonFly__
 #  include <unistd.h>
 #  include <fcntl.h>
 #  include <elf.h>
