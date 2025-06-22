--- lib/TargetParser/Triple.cpp.orig	2025-06-13 04:54:32 UTC
+++ lib/TargetParser/Triple.cpp
@@ -672,6 +672,7 @@ static Triple::OSType parseOS(StringRef
     .StartsWith("darwin", Triple::Darwin)
     .StartsWith("dragonfly", Triple::DragonFly)
     .StartsWith("freebsd", Triple::FreeBSD)
+    .StartsWith("midnightbsd", Triple::FreeBSD)
     .StartsWith("fuchsia", Triple::Fuchsia)
     .StartsWith("ios", Triple::IOS)
     .StartsWith("kfreebsd", Triple::KFreeBSD)
