--- Source/WTF/wtf/NumberOfCores.cpp.orig	2024-08-19 06:28:38 UTC
+++ Source/WTF/wtf/NumberOfCores.cpp
@@ -32,6 +32,7 @@
 #if OS(DARWIN)
 #include <sys/sysctl.h>
 #elif OS(LINUX) || OS(AIX) || OS(OPENBSD) || OS(NETBSD) || OS(FREEBSD)
+#include <stdio.h> // sscanf
 #include <unistd.h>
 #elif OS(WINDOWS)
 #include <windows.h>
