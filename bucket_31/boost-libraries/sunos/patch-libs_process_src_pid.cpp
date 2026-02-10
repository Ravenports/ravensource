--- libs/process/src/pid.cpp.orig	2025-12-03 13:46:45 UTC
+++ libs/process/src/pid.cpp
@@ -42,6 +42,8 @@
 #include <sys/sysctl.h>
 #include <sys/user.h>
 #include <kvm.h>
+#include <fcntl.h>
+#include <memory>
 #endif
 
 #if defined(__NetBSD__)
