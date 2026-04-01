--- lib/TargetParser/Triple.cpp.orig	2026-03-23 18:46:22 UTC
+++ lib/TargetParser/Triple.cpp
@@ -711,6 +711,7 @@ static Triple::OSType parseOS(StringRef
       .StartsWith("darwin", Triple::Darwin)
       .StartsWith("dragonfly", Triple::DragonFly)
       .StartsWith("freebsd", Triple::FreeBSD)
+      .StartsWith("midnightbsd", Triple::FreeBSD)
       .StartsWith("fuchsia", Triple::Fuchsia)
       .StartsWith("ios", Triple::IOS)
       .StartsWith("kfreebsd", Triple::KFreeBSD)
