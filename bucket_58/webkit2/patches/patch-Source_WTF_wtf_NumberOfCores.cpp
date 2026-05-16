--- Source/WTF/wtf/NumberOfCores.cpp.orig	2026-02-23 14:40:54 UTC
+++ Source/WTF/wtf/NumberOfCores.cpp
@@ -33,6 +33,7 @@
 #if OS(DARWIN)
 #include <sys/sysctl.h>
 #elif OS(LINUX) || OS(AIX) || OS(OPENBSD) || OS(NETBSD) || OS(FREEBSD) || OS(HAIKU)
+#include <stdio.h> // sscanf
 #include <unistd.h>
 #elif OS(QNX)
 #include <sys/syspage.h>
