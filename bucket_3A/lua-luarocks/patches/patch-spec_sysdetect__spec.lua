--- spec/sysdetect_spec.lua.orig	2022-12-08 20:13:08 UTC
+++ spec/sysdetect_spec.lua
@@ -52,6 +52,7 @@ describe("luarocks.core.sysdetect #unix
       ["elf-OpenBSD-x86_64-sh"] = {"openbsd", "x86_64"},
       ["elf-NetBSD-x86_64-echo"] = {"netbsd", "x86_64"},
       ["elf-FreeBSD-x86_64-echo"] = {"freebsd", "x86_64"},
+      ["elf-MidnightBSD-x86_64-echo"] = {"midnightbsd", "x86_64"},
       ["elf-Haiku-GCC2-ls"] = {"haiku", "x86"},
       ["elf-Haiku-GCC7-WebPositive"] = {"haiku", "x86"},
       ["pe-cygwin-ls.exe"] = {"cygwin", "x86"},
