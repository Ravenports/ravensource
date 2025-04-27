--- source/Plugins/Platform/FreeBSD/PlatformFreeBSD.cpp.orig	2025-04-16 00:23:49 UTC
+++ source/Plugins/Platform/FreeBSD/PlatformFreeBSD.cpp
@@ -59,7 +59,7 @@ PlatformSP PlatformFreeBSD::CreateInstan
       create = true;
       break;
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
     // Only accept "unknown" for the OS if the host is BSD and it "unknown"
     // wasn't specified (it was just returned because it was NOT specified)
     case llvm::Triple::OSType::UnknownOS:
@@ -87,7 +87,7 @@ void PlatformFreeBSD::Initialize() {
   Platform::Initialize();
 
   if (g_initialize_count++ == 0) {
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
     PlatformSP default_platform_sp(new PlatformFreeBSD(true));
     default_platform_sp->SetSystemArchitecture(HostInfo::GetArchitecture());
     Platform::SetHostPlatform(default_platform_sp);
