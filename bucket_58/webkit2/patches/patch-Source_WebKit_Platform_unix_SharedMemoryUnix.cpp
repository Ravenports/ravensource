--- Source/WebKit/Platform/unix/SharedMemoryUnix.cpp.orig	2023-02-20 09:22:20 UTC
+++ Source/WebKit/Platform/unix/SharedMemoryUnix.cpp
@@ -129,7 +129,11 @@ static UnixFileDescriptor createSharedMe
 #else
     CString tempName;
     for (int tries = 0; fileDescriptor == -1 && tries < 10; ++tries) {
+# ifdef __DragonFly__
+        auto name = makeString("/tmp/WK2SharedMemory.", cryptographicallyRandomNumber<unsigned>());
+# else
         auto name = makeString("/WK2SharedMemory.", cryptographicallyRandomNumber<unsigned>());
+# endif
         tempName = name.utf8();
 
         do {
