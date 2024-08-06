--- Makefile.PL.orig	2022-08-30 07:11:25 UTC
+++ Makefile.PL
@@ -27,6 +27,8 @@ my %WriteMakefileArgs = (
     "lib/Alien/Role/Dino/MSWin32.pm"        => "\$(INST_LIB)/Alien/Role/Dino/MSWin32.pm",
     "lib/Alien/Role/Dino/cygwin.pm"         => "\$(INST_LIB)/Alien/Role/Dino/cygwin.pm",
     "lib/Alien/Role/Dino/darwin.pm"         => "\$(INST_LIB)/Alien/Role/Dino/darwin.pm",
+    "lib/Alien/Role/Dino/dragonfly.pm"      => "\$(INST_LIB)/Alien/Role/Dino/dragonfly.pm",
+    "lib/Alien/Role/Dino/midnightbsd.pm"    => "\$(INST_LIB)/Alien/Role/Dino/midnightbsd.pm",
     "lib/Alien/Role/Dino/freebsd.pm"        => "\$(INST_LIB)/Alien/Role/Dino/freebsd.pm",
     "lib/Alien/Role/Dino/gnukfreebsd.pm"    => "\$(INST_LIB)/Alien/Role/Dino/gnukfreebsd.pm",
     "lib/Alien/Role/Dino/linux.pm"          => "\$(INST_LIB)/Alien/Role/Dino/linux.pm",
