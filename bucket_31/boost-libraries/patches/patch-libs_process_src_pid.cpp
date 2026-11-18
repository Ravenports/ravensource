--- libs/process/src/pid.cpp.orig	2026-08-05 17:09:13 UTC
+++ libs/process/src/pid.cpp
@@ -42,6 +42,8 @@
 #include <sys/sysctl.h>
 #include <sys/user.h>
 #include <kvm.h>
+#include <fcntl.h>
+#include <memory>
 #endif
 
 #if defined(__NetBSD__)
