--- library/std/src/alloc.rs.orig	2023-05-31 19:28:10 UTC
+++ library/std/src/alloc.rs
@@ -330,18 +330,7 @@ pub fn take_alloc_error_hook() -> fn(Lay
 }
 
 fn default_alloc_error_hook(layout: Layout) {
-    extern "Rust" {
-        // This symbol is emitted by rustc next to __rust_alloc_error_handler.
-        // Its value depends on the -Zoom={panic,abort} compiler option.
-        static __rust_alloc_error_handler_should_panic: u8;
-    }
-
-    #[allow(unused_unsafe)]
-    if unsafe { __rust_alloc_error_handler_should_panic != 0 } {
         panic!("memory allocation of {} bytes failed", layout.size());
-    } else {
-        rtprintpanic!("memory allocation of {} bytes failed\n", layout.size());
-    }
 }
 
 #[cfg(not(test))]
