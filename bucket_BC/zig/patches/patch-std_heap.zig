--- std/heap.zig.orig	2019-04-08 19:41:41 UTC
+++ std/heap.zig
@@ -61,7 +61,7 @@ pub const DirectAllocator = struct {
         const self = @fieldParentPtr(DirectAllocator, "allocator", allocator);
 
         switch (builtin.os) {
-            Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd => {
+            Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd, Os.dragonfly => {
                 const p = os.posix;
                 const alloc_size = if (alignment <= os.page_size) n else n + alignment;
                 const addr = p.mmap(null, alloc_size, p.PROT_READ | p.PROT_WRITE, p.MAP_PRIVATE | p.MAP_ANONYMOUS, -1, 0);
@@ -108,7 +108,7 @@ pub const DirectAllocator = struct {
 
     fn shrink(allocator: *Allocator, old_mem: []u8, old_align: u29, new_size: usize, new_align: u29) []u8 {
         switch (builtin.os) {
-            Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd => {
+            Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd, Os.dragonfly => {
                 const base_addr = @ptrToInt(old_mem.ptr);
                 const old_addr_end = base_addr + old_mem.len;
                 const new_addr_end = base_addr + new_size;
@@ -133,7 +133,7 @@ pub const DirectAllocator = struct {
 
     fn realloc(allocator: *Allocator, old_mem: []u8, old_align: u29, new_size: usize, new_align: u29) ![]u8 {
         switch (builtin.os) {
-            Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd => {
+            Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd, Os.dragonfly => {
                 if (new_size <= old_mem.len and new_align <= old_align) {
                     return shrink(allocator, old_mem, old_align, new_size, new_align);
                 }
