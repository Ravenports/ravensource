--- lib/TargetParser/Triple.cpp.orig	2023-06-10 22:58:16 UTC
+++ lib/TargetParser/Triple.cpp
@@ -562,6 +562,7 @@ static Triple::OSType parseOS(StringRef
     .StartsWith("darwin", Triple::Darwin)
     .StartsWith("dragonfly", Triple::DragonFly)
     .StartsWith("freebsd", Triple::FreeBSD)
+    .StartsWith("midnightbsd", Triple::FreeBSD)
     .StartsWith("fuchsia", Triple::Fuchsia)
     .StartsWith("ios", Triple::IOS)
     .StartsWith("kfreebsd", Triple::KFreeBSD)
