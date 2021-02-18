--- deps/v8/src/base/platform/platform-freebsd.cc.orig	2021-02-18 01:02:02 UTC
+++ deps/v8/src/base/platform/platform-freebsd.cc
@@ -48,6 +48,9 @@ static unsigned StringToLong(char* buffe
 }
 
 std::vector<OS::SharedLibraryAddress> OS::GetSharedLibraryAddresses() {
+#ifdef __DragonFly__
+  return std::vector<SharedLibraryAddress>();
+#else
   std::vector<SharedLibraryAddress> result;
   int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_VMMAP, getpid()};
   size_t miblen = sizeof(mib) / sizeof(mib[0]);
@@ -91,6 +94,7 @@ std::vector<OS::SharedLibraryAddress> OS
     }
   }
   return result;
+#endif
 }
 
 void OS::SignalCodeMovingGC() {}
