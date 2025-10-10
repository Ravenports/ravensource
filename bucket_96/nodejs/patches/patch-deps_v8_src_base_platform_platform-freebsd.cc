--- deps/v8/src/base/platform/platform-freebsd.cc.orig	2025-09-25 14:43:12 UTC
+++ deps/v8/src/base/platform/platform-freebsd.cc
@@ -48,7 +48,10 @@ static unsigned StringToLong(char* buffe
 }
 
 std::vector<OS::SharedLibraryAddress> OS::GetSharedLibraryAddresses() {
-  std::vector<SharedLibraryAddress> result;
+#ifdef __DragonFly__
+  return std::vector<SharedLibraryAddress>();
+#else
+  std::vector<SharedLibraryAddress> address_result;
   int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_VMMAP, getpid()};
   size_t miblen = sizeof(mib) / sizeof(mib[0]);
   size_t buffer_size;
@@ -81,7 +84,7 @@ std::vector<OS::SharedLibraryAddress> OS
           } else {
             lib_name = std::string(path);
           }
-          result.push_back(SharedLibraryAddress(
+          address_result.push_back(SharedLibraryAddress(
               lib_name, reinterpret_cast<uintptr_t>(map->kve_start),
               reinterpret_cast<uintptr_t>(map->kve_end)));
         }
@@ -90,7 +93,8 @@ std::vector<OS::SharedLibraryAddress> OS
       }
     }
   }
-  return result;
+  return address_result;
+#endif
 }
 
 void OS::SignalCodeMovingGC() {}
