--- Source/WebCore/platform/unix/SharedMemoryUnix.cpp.orig	2025-02-25 08:25:41 UTC
+++ Source/WebCore/platform/unix/SharedMemoryUnix.cpp
@@ -104,7 +104,11 @@ static UnixFileDescriptor createSharedMe
 #else
     CString tempName;
     for (int tries = 0; fileDescriptor == -1 && tries < 10; ++tries) {
+# ifdef __DragonFly__
         auto name = makeString("/WK2SharedMemory."_s, cryptographicallyRandomNumber<unsigned>());
+# else
+        auto name = makeString("/tmp/WK2SharedMemory."_s, cryptographicallyRandomNumber<unsigned>());
+# endif
         tempName = name.utf8();
 
         do {
