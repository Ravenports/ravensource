--- vendor/os_info/src/freebsd/mod.rs.orig	2023-08-23 22:08:20 UTC
+++ vendor/os_info/src/freebsd/mod.rs
@@ -30,17 +30,7 @@ fn get_os() -> Type {
         .expect("Failed to get OS");
 
     match str::from_utf8(&os.stdout) {
-        Ok("FreeBSD\n") => {
-            let check_hardening = Command::new("sysctl")
-                .arg("hardening.version")
-                .output()
-                .expect("Failed to check if is hardened");
-            match str::from_utf8(&check_hardening.stderr) {
-                Ok("0\n") => Type::HardenedBSD,
-                Ok(_) => Type::FreeBSD,
-                Err(_) => Type::FreeBSD,
-            }
-        }
+        Ok("FreeBSD\n") => Type::FreeBSD,
         Ok("MidnightBSD\n") => Type::MidnightBSD,
         Ok(_) => Type::Unknown,
         Err(_) => Type::Unknown,
