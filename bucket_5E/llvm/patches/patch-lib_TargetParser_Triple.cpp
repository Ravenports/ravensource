--- lib/TargetParser/Triple.cpp.orig	2024-10-15 08:17:37 UTC
+++ lib/TargetParser/Triple.cpp
@@ -645,6 +645,7 @@ static Triple::OSType parseOS(StringRef
     .StartsWith("darwin", Triple::Darwin)
     .StartsWith("dragonfly", Triple::DragonFly)
     .StartsWith("freebsd", Triple::FreeBSD)
+    .StartsWith("midnightbsd", Triple::FreeBSD)
     .StartsWith("fuchsia", Triple::Fuchsia)
     .StartsWith("ios", Triple::IOS)
     .StartsWith("kfreebsd", Triple::KFreeBSD)
