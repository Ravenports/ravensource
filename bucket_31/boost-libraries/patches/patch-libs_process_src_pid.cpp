--- libs/process/src/pid.cpp.orig	2025-08-06 18:49:13 UTC
+++ libs/process/src/pid.cpp
@@ -42,6 +42,8 @@
 #include <sys/sysctl.h>
 #include <sys/user.h>
 #include <kvm.h>
+#include <fcntl.h>
+#include <memory>
 #endif
 
 #if defined(__NetBSD__)
