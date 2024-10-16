--- Source/WebCore/platform/unix/SharedMemoryUnix.cpp.orig	2024-08-19 06:28:39 UTC
+++ Source/WebCore/platform/unix/SharedMemoryUnix.cpp
@@ -98,7 +98,11 @@ static UnixFileDescriptor createSharedMe
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
