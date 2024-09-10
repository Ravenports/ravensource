--- libs/process/src/pid.cpp.orig	2024-08-07 22:07:40 UTC
+++ libs/process/src/pid.cpp
@@ -38,6 +38,8 @@
 #include <sys/sysctl.h>
 #include <sys/user.h>
 #include <kvm.h>
+#include <fcntl.h>
+#include <memory>
 #endif
 
 #if defined(__NetBSD__)
