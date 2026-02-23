--- lib/Alien/Build/Plugin/Core/Setup.pm.orig	2024-10-29 00:51:50 UTC
+++ lib/Alien/Build/Plugin/Core/Setup.pm
@@ -192,6 +192,7 @@ sub _cpu_arch {
       \b x64    \b # MSWin32-x64
     | \b x86_64 \b # x86_64-linux
     | \b amd64  \b # amd64-freebsd
+    | \b i86pc  \b # i86pc-solaris-thread-multi-64
     /ix) {
     $arch = { name => 'x86_64' };
   } elsif( $Config{archname} =~ m/
