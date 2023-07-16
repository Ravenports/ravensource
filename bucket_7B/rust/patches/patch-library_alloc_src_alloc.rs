--- library/alloc/src/alloc.rs.orig	2023-07-12 03:32:40 UTC
+++ library/alloc/src/alloc.rs
@@ -406,20 +406,7 @@ pub mod __alloc_error_handler {
     // `#[alloc_error_handler]`.
     #[rustc_std_internal_symbol]
     pub unsafe fn __rdl_oom(size: usize, _align: usize) -> ! {
-        extern "Rust" {
-            // This symbol is emitted by rustc next to __rust_alloc_error_handler.
-            // Its value depends on the -Zoom={panic,abort} compiler option.
-            static __rust_alloc_error_handler_should_panic: u8;
-        }
-
-        #[allow(unused_unsafe)]
-        if unsafe { __rust_alloc_error_handler_should_panic != 0 } {
             panic!("memory allocation of {size} bytes failed")
-        } else {
-            core::panicking::panic_nounwind_fmt(format_args!(
-                "memory allocation of {size} bytes failed"
-            ))
-        }
     }
 }
 
