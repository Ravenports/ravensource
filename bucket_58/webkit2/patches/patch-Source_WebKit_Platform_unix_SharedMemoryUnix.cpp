--- Source/WebKit/Platform/unix/SharedMemoryUnix.cpp.orig	2022-09-14 11:58:10 UTC
+++ Source/WebKit/Platform/unix/SharedMemoryUnix.cpp
@@ -148,7 +148,13 @@ static int createSharedMemory()
 #else
     CString tempName;
     for (int tries = 0; fileDescriptor == -1 && tries < 10; ++tries) {
-        auto name = makeString("/WK2SharedMemory.", static_cast<unsigned>(WTF::randomNumber() * (std::numeric_limits<unsigned>::max() + 1.0)));
+        auto name =
+#ifdef __DragonFly__
+   makeString("/tmp/WK2SharedMemory.",
+#else
+   makeString("/WK2SharedMemory.",
+#endif
+   static_cast<unsigned>(WTF::randomNumber() * (std::numeric_limits<unsigned>::max() + 1.0)));
         tempName = name.utf8();
 
         do {
