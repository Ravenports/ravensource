--- vendor/openssl-src/src/lib.rs.orig	2019-04-10 20:18:53 UTC
+++ vendor/openssl-src/src/lib.rs
@@ -145,6 +145,7 @@ impl Build {
             "i686-linux-android" => "linux-elf",
             "i686-pc-windows-gnu" => "mingw",
             "i686-pc-windows-msvc" => "VC-WIN32",
+            "x86_64-unknown-dragonfly" => "BSD-x86_64",
             "i686-unknown-freebsd" => "BSD-x86-elf",
             "i686-unknown-linux-gnu" => "linux-elf",
             "i686-unknown-linux-musl" => "linux-elf",
