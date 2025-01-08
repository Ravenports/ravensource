--- CPP/Windows/System.cpp.orig	2024-10-17 08:03:40 UTC
+++ CPP/Windows/System.cpp
@@ -44,7 +44,7 @@ namespace NWindows
 		#elif defined (__FreeBSD__) || defined (__FreeBSD_kernel__)
 		UInt32 GetNumberOfProcessors() {
 		  	int nbcpu = 1;
-			size_t value;
+			int value;
 			size_t len = sizeof(value);
 			if (sysctlbyname("hw.ncpu", &value, &len, NULL, 0) == 0)
 				nbcpu = value;
