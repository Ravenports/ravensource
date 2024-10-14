--- mozglue/static/rust/lib.rs.orig	2024-07-04 17:04:21 UTC
+++ mozglue/static/rust/lib.rs
@@ -157,7 +157,7 @@ extern "C" {
     fn _aligned_free(ptr: *mut c_void);
 
     #[cfg(not(windows))]
-    fn memalign(align: usize, size: usize) -> *mut c_void;
+    fn posix_memalign(ptr: *mut *mut c_void, alignment: usize, size: usize) -> c_int;
 }
 
 #[cfg(windows)]
@@ -177,7 +177,9 @@ fn need_memalign(layout: Layout) -> bool
 unsafe impl GlobalAlloc for GeckoAlloc {
     unsafe fn alloc(&self, layout: Layout) -> *mut u8 {
         if need_memalign(layout) {
-            memalign(layout.align(), layout.size()) as *mut u8
+            let mut ptr: *mut c_void = std::ptr::null_mut(); 
+            let _err = posix_memalign(&mut ptr, layout.align(), layout.size());
+            return ptr as *mut u8;
         } else {
             malloc(layout.size()) as *mut u8
         }
