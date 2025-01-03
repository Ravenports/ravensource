--- libs/process/src/pid.cpp.orig	2024-12-05 00:53:35 UTC
+++ libs/process/src/pid.cpp
@@ -42,6 +42,8 @@
 #include <sys/sysctl.h>
 #include <sys/user.h>
 #include <kvm.h>
+#include <fcntl.h>
+#include <memory>
 #endif
 
 #if defined(__NetBSD__)
