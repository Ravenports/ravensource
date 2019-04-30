--- src/target.cpp.orig	2019-04-08 19:41:41 UTC
+++ src/target.cpp
@@ -857,6 +857,7 @@ uint32_t target_c_type_size_in_bits(cons
         case OsLinux:
         case OsMacOSX:
         case OsZen:
+        case OsDragonFly:
         case OsFreeBSD:
         case OsNetBSD:
         case OsOpenBSD:
@@ -896,7 +897,6 @@ uint32_t target_c_type_size_in_bits(cons
             }
         case OsAnanas:
         case OsCloudABI:
-        case OsDragonFly:
         case OsIOS:
         case OsKFreeBSD:
         case OsLv2:
@@ -1009,6 +1009,8 @@ static bool is_64_bit(ZigLLVM_ArchType a
 
 const char *target_dynamic_linker(const ZigTarget *target) {
     switch (target->os) {
+        case OsDragonFly:
+            return "/libexec/ld-elf.so.2";
         case OsFreeBSD:
             return "/libexec/ld-elf.so.1";
         case OsNetBSD:
@@ -1133,7 +1135,6 @@ const char *target_dynamic_linker(const
 
         case OsAnanas:
         case OsCloudABI:
-        case OsDragonFly:
         case OsFuchsia:
         case OsKFreeBSD:
         case OsLv2:
@@ -1327,7 +1328,7 @@ bool target_os_requires_libc(Os os) {
     // On Darwin, we always link libSystem which contains libc.
     // Similarly on FreeBSD and NetBSD we always link system libc
     // since this is the stable syscall interface.
-    return (target_os_is_darwin(os) || os == OsFreeBSD || os == OsNetBSD);
+    return (target_os_is_darwin(os) || os == OsFreeBSD || os == OsNetBSD || os == OsDragonFly);
 }
 
 bool target_supports_fpic(const ZigTarget *target) {
@@ -1355,7 +1356,6 @@ ZigLLVM_EnvironmentType target_default_a
         case OsFreestanding:
         case OsAnanas:
         case OsCloudABI:
-        case OsDragonFly:
         case OsLv2:
         case OsSolaris:
         case OsHaiku:
@@ -1378,6 +1378,7 @@ ZigLLVM_EnvironmentType target_default_a
         case OsOpenBSD:
         case OsMacOSX:
         case OsFreeBSD:
+        case OsDragonFly:
         case OsIOS:
         case OsTvOS:
         case OsWatchOS:
