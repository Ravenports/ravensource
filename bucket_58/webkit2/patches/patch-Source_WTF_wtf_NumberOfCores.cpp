--- Source/WTF/wtf/NumberOfCores.cpp.orig	2025-08-11 07:56:53 UTC
+++ Source/WTF/wtf/NumberOfCores.cpp
@@ -33,6 +33,7 @@
 #if OS(DARWIN)
 #include <sys/sysctl.h>
 #elif OS(LINUX) || OS(AIX) || OS(OPENBSD) || OS(NETBSD) || OS(FREEBSD) || OS(HAIKU)
+#include <stdio.h> // sscanf
 #include <unistd.h>
 #elif OS(WINDOWS)
 #include <windows.h>
