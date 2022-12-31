--- vendor/openssl-sys/build/main.rs.orig	2022-11-02 16:21:42 UTC
+++ vendor/openssl-sys/build/main.rs
@@ -254,6 +254,9 @@ See rust-openssl README for more informa
             (3, 3, _) => ('3', '3', 'x'),
             (3, 4, 0) => ('3', '4', '0'),
             (3, 4, _) => ('3', '4', 'x'),
+            (3, 5, _) => ('3', '5', 'x'),
+            (3, 6, 0) => ('3', '6', '0'),
+            (3, 6, _) => ('3', '6', 'x'),
             _ => version_error(),
         };
 
