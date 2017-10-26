--- modules/core/src/system.cpp.orig	2017-10-23 15:41:12 UTC
+++ modules/core/src/system.cpp
@@ -67,7 +67,7 @@ Mutex* __initialization_mutex_initialize
 # endif
 #endif
 
-#if defined __ANDROID__ || defined __linux__ || defined __FreeBSD__ || defined __HAIKU__
+#if defined __ANDROID__ || defined __linux__ || defined __FreeBSD__ || defined __HAIKU__ || defined __DragonFly__
 #  include <unistd.h>
 #  include <fcntl.h>
 #  include <elf.h>
