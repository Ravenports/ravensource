--- Source/WTF/wtf/NumberOfCores.cpp.orig	2025-02-25 08:25:40 UTC
+++ Source/WTF/wtf/NumberOfCores.cpp
@@ -32,6 +32,7 @@
 #if OS(DARWIN)
 #include <sys/sysctl.h>
 #elif OS(LINUX) || OS(AIX) || OS(OPENBSD) || OS(NETBSD) || OS(FREEBSD) || OS(HAIKU)
+#include <stdio.h> // sscanf
 #include <unistd.h>
 #elif OS(WINDOWS)
 #include <windows.h>
