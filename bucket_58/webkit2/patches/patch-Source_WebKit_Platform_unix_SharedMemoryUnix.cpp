--- Source/WebKit/Platform/unix/SharedMemoryUnix.cpp.orig	2020-08-12 09:17:56 UTC
+++ Source/WebKit/Platform/unix/SharedMemoryUnix.cpp
@@ -137,7 +137,13 @@ static int createSharedMemory()
 
     CString tempName;
     for (int tries = 0; fileDescriptor == -1 && tries < 10; ++tries) {
-        String name = String("/WK2SharedMemory.") + String::number(static_cast<unsigned>(WTF::randomNumber() * (std::numeric_limits<unsigned>::max() + 1.0)));
+        String name =
+#ifdef __DragonFly__
+                      String("/tmp/WK2SharedMemory.")
+#else
+                      String("/WK2SharedMemory.")
+#endif
+                      + String::number(static_cast<unsigned>(WTF::randomNumber() * (std::numeric_limits<unsigned>::max() + 1.0)));
         tempName = name.utf8();
 
         do {
