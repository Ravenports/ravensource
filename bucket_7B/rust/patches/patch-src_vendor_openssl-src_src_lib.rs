--- src/vendor/openssl-src/src/lib.rs.orig	2018-12-05 01:24:31 UTC
+++ src/vendor/openssl-src/src/lib.rs
@@ -160,6 +160,7 @@ impl Build {
             "x86_64-linux-android" => "linux-x86_64",
             "x86_64-pc-windows-gnu" => "mingw64",
             "x86_64-pc-windows-msvc" => "VC-WIN64A",
+            "x86_64-unknown-dragonfly" => "BSD-x86_64",
             "x86_64-unknown-freebsd" => "BSD-x86_64",
             "x86_64-unknown-linux-gnu" => "linux-x86_64",
             "x86_64-unknown-linux-musl" => "linux-x86_64",
