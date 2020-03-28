--- deps/v8/src/base/platform/platform-freebsd.cc.orig	2020-03-26 20:00:01 UTC
+++ deps/v8/src/base/platform/platform-freebsd.cc
@@ -47,6 +47,9 @@ static unsigned StringToLong(char* buffe
 }
 
 std::vector<OS::SharedLibraryAddress> OS::GetSharedLibraryAddresses() {
+#ifdef __DragonFly__
+  return std::vector<SharedLibraryAddress>();
+#else
   std::vector<SharedLibraryAddress> result;
   int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_VMMAP, getpid()};
   size_t miblen = sizeof(mib) / sizeof(mib[0]);
@@ -90,6 +93,7 @@ std::vector<OS::SharedLibraryAddress> OS
     }
   }
   return result;
+#endif
 }
 
 void OS::SignalCodeMovingGC() {}
