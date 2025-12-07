--- Source/WebCore/platform/unix/SharedMemoryUnix.cpp.orig	2025-08-11 07:56:55 UTC
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
