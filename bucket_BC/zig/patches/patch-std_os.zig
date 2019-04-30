--- std/os.zig.orig	2019-04-08 19:41:41 UTC
+++ std/os.zig
@@ -3,7 +3,7 @@ const builtin = @import("builtin");
 const Os = builtin.Os;
 const is_windows = builtin.os == Os.windows;
 const is_posix = switch (builtin.os) {
-    builtin.Os.linux, builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd => true,
+    Os.linux, Os.macosx, Os.freebsd, Os.netbsd, Os.dragonfly => true,
     else => false,
 };
 const os = @This();
@@ -31,6 +31,7 @@ pub const darwin = @import("os/darwin.zi
 pub const linux = @import("os/linux.zig");
 pub const freebsd = @import("os/freebsd.zig");
 pub const netbsd = @import("os/netbsd.zig");
+pub const dragonfly = @import("os/dragonfly.zig");
 pub const zen = @import("os/zen.zig");
 pub const uefi = @import("os/uefi.zig");
 
@@ -39,6 +40,7 @@ pub const posix = switch (builtin.os) {
     Os.macosx, Os.ios => darwin,
     Os.freebsd => freebsd,
     Os.netbsd => netbsd,
+    Os.dragonfly => dragonfly,
     Os.zen => zen,
     else => @compileError("Unsupported OS"),
 };
@@ -52,7 +54,7 @@ pub const time = @import("os/time.zig");
 
 pub const page_size = 4 * 1024;
 pub const MAX_PATH_BYTES = switch (builtin.os) {
-    Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd => posix.PATH_MAX,
+    Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd, Os.dragonfly => posix.PATH_MAX,
     // Each UTF-16LE character may be expanded to 3 UTF-8 bytes.
     // If it would require 4 UTF-8 bytes, then there would be a surrogate
     // pair in the UTF-16LE, and we (over)account 3 bytes for it that way.
@@ -127,7 +129,7 @@ pub fn getRandomBytes(buf: []u8) !void {
                 else => return unexpectedErrorPosix(errno),
             }
         },
-        Os.macosx, Os.ios, Os.freebsd, Os.netbsd => return getRandomBytesDevURandom(buf),
+        Os.macosx, Os.ios, Os.freebsd, Os.netbsd, Os.dragonfly => return getRandomBytesDevURandom(buf),
         Os.windows => {
             // Call RtlGenRandom() instead of CryptGetRandom() on Windows
             // https://github.com/rust-lang-nursery/rand/issues/111
@@ -187,7 +189,7 @@ pub fn abort() noreturn {
         c.abort();
     }
     switch (builtin.os) {
-        Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd => {
+        Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd, Os.dragonfly => {
             _ = posix.raise(posix.SIGABRT);
             _ = posix.raise(posix.SIGKILL);
             while (true) {}
@@ -220,7 +222,7 @@ pub fn exit(status: u8) noreturn {
                 linux.exit_group(status);
             }
         },
-        Os.macosx, Os.ios, Os.freebsd, Os.netbsd => {
+        Os.macosx, Os.ios, Os.freebsd, Os.netbsd, Os.dragonfly => {
             posix.exit(status);
         },
         Os.windows => {
@@ -299,7 +301,7 @@ pub fn posixRead(fd: i32, buf: []u8) Pos
 /// Number of bytes read is returned. Upon reading end-of-file, zero is returned.
 pub fn posix_preadv(fd: i32, iov: [*]const posix.iovec, count: usize, offset: u64) PosixReadError!usize {
     switch (builtin.os) {
-        builtin.Os.macosx => {
+        Os.macosx => {
             // Darwin does not have preadv but it does have pread.
             var off: usize = 0;
             var iov_i: usize = 0;
@@ -336,7 +338,7 @@ pub fn posix_preadv(fd: i32, iov: [*]con
                 }
             }
         },
-        builtin.Os.linux, builtin.Os.freebsd, Os.netbsd => while (true) {
+        Os.linux, Os.freebsd, Os.netbsd, Os.dragonfly => while (true) {
             const rc = posix.preadv(fd, iov, count, offset);
             const err = posix.getErrno(rc);
             switch (err) {
@@ -404,7 +406,7 @@ pub fn posixWrite(fd: i32, bytes: []cons
 
 pub fn posix_pwritev(fd: i32, iov: [*]const posix.iovec_const, count: usize, offset: u64) PosixWriteError!void {
     switch (builtin.os) {
-        builtin.Os.macosx => {
+        Os.macosx => {
             // Darwin does not have pwritev but it does have pwrite.
             var off: usize = 0;
             var iov_i: usize = 0;
@@ -443,7 +445,7 @@ pub fn posix_pwritev(fd: i32, iov: [*]co
                 }
             }
         },
-        builtin.Os.linux, builtin.Os.freebsd, builtin.Os.netbsd => while (true) {
+        Os.linux, Os.freebsd, Os.netbsd, Os.dragonfly => while (true) {
             const rc = posix.pwritev(fd, iov, count, offset);
             const err = posix.getErrno(rc);
             switch (err) {
@@ -700,7 +702,7 @@ pub fn linuxGetAuxVal(index: usize) usiz
 
 pub fn getBaseAddress() usize {
     switch (builtin.os) {
-        builtin.Os.linux => {
+        Os.linux => {
             const base = linuxGetAuxVal(std.elf.AT_BASE);
             if (base != 0) {
                 return base;
@@ -708,10 +710,10 @@ pub fn getBaseAddress() usize {
             const phdr = linuxGetAuxVal(std.elf.AT_PHDR);
             return phdr - @sizeOf(std.elf.Ehdr);
         },
-        builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd => {
+        Os.macosx, Os.freebsd, Os.netbsd, Os.dragonfly => {
             return @ptrToInt(&std.c._mh_execute_header);
         },
-        builtin.Os.windows => return @ptrToInt(windows.GetModuleHandleW(null)),
+        Os.windows => return @ptrToInt(windows.GetModuleHandleW(null)),
         else => @compileError("Unsupported OS"),
     }
 }
@@ -1350,7 +1352,7 @@ pub fn deleteDirC(dir_path: [*]const u8)
             const dir_path_w = try windows_util.cStrToPrefixedFileW(dir_path);
             return deleteDirW(&dir_path_w);
         },
-        Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd => {
+        Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd, Os.dragonfly => {
             const err = posix.getErrno(posix.rmdir(dir_path));
             switch (err) {
                 0 => return,
@@ -1393,7 +1395,7 @@ pub fn deleteDir(dir_path: []const u8) D
             const dir_path_w = try windows_util.sliceToPrefixedFileW(dir_path);
             return deleteDirW(&dir_path_w);
         },
-        Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd => {
+        Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd, Os.dragonfly => {
             const dir_path_c = try toPosixPath(dir_path);
             return deleteDirC(&dir_path_c);
         },
@@ -1512,7 +1514,7 @@ pub const Dir = struct {
     allocator: *Allocator,
 
     pub const Handle = switch (builtin.os) {
-        Os.macosx, Os.ios, Os.freebsd, Os.netbsd => struct {
+        Os.macosx, Os.ios, Os.freebsd, Os.netbsd, Os.dragonfly => struct {
             fd: i32,
             seek: i64,
             buf: []u8,
@@ -1589,7 +1591,7 @@ pub const Dir = struct {
                         .name_data = undefined,
                     };
                 },
-                Os.macosx, Os.ios, Os.freebsd, Os.netbsd => Handle{
+                Os.macosx, Os.ios, Os.freebsd, Os.netbsd, Os.dragonfly => Handle{
                     .fd = try posixOpen(
                         dir_path,
                         posix.O_RDONLY | posix.O_NONBLOCK | posix.O_DIRECTORY | posix.O_CLOEXEC,
@@ -1620,7 +1622,7 @@ pub const Dir = struct {
             Os.windows => {
                 _ = windows.FindClose(self.handle.handle);
             },
-            Os.macosx, Os.ios, Os.linux, Os.freebsd, Os.netbsd => {
+            Os.macosx, Os.ios, Os.linux, Os.freebsd, Os.netbsd, Os.dragonfly => {
                 self.allocator.free(self.handle.buf);
                 os.close(self.handle.fd);
             },
@@ -1637,6 +1639,7 @@ pub const Dir = struct {
             Os.windows => return self.nextWindows(),
             Os.freebsd => return self.nextFreebsd(),
             Os.netbsd => return self.nextFreebsd(),
+            Os.dragonfly => return self.nextFreebsd(),
             else => @compileError("unimplemented"),
         }
     }
@@ -2262,7 +2265,7 @@ pub fn unexpectedErrorWindows(err: windo
 pub fn openSelfExe() !os.File {
     switch (builtin.os) {
         Os.linux => return os.File.openReadC(c"/proc/self/exe"),
-        Os.macosx, Os.ios, Os.freebsd, Os.netbsd => {
+        Os.macosx, Os.ios, Os.freebsd, Os.netbsd, Os.dragonfly => {
             var buf: [MAX_PATH_BYTES]u8 = undefined;
             const self_exe_path = try selfExePath(&buf);
             buf[self_exe_path.len] = 0;
@@ -2279,7 +2282,7 @@ pub fn openSelfExe() !os.File {
 
 test "openSelfExe" {
     switch (builtin.os) {
-        Os.linux, Os.macosx, Os.ios, Os.windows, Os.freebsd => (try openSelfExe()).close(),
+        Os.linux, Os.macosx, Os.ios, Os.windows, Os.freebsd, Os.dragonfly => (try openSelfExe()).close(),
         else => return error.SkipZigTest, // Unsupported OS.
     }
 }
@@ -2310,7 +2313,7 @@ pub fn selfExePathW(out_buffer: *[window
 pub fn selfExePath(out_buffer: *[MAX_PATH_BYTES]u8) ![]u8 {
     switch (builtin.os) {
         Os.linux => return readLink(out_buffer, "/proc/self/exe"),
-        Os.freebsd => {
+        Os.freebsd, Os.dragonfly => {
             var mib = [4]c_int{ posix.CTL_KERN, posix.KERN_PROC, posix.KERN_PROC_PATHNAME, -1 };
             var out_len: usize = out_buffer.len;
             const err = posix.getErrno(posix.sysctl(&mib, 4, out_buffer, &out_len, null, 0));
@@ -2374,7 +2377,7 @@ pub fn selfExeDirPath(out_buffer: *[MAX_
             // will not return null.
             return path.dirname(full_exe_path).?;
         },
-        Os.windows, Os.macosx, Os.ios, Os.freebsd, Os.netbsd => {
+        Os.windows, Os.macosx, Os.ios, Os.freebsd, Os.netbsd, Os.dragonfly => {
             const self_exe_path = try selfExePath(out_buffer);
             // Assume that the OS APIs return absolute paths, and therefore dirname
             // will not return null.
@@ -2910,8 +2913,8 @@ pub const Thread = struct {
     pub const Handle = if (use_pthreads)
         c.pthread_t
     else switch (builtin.os) {
-        builtin.Os.linux => i32,
-        builtin.Os.windows => windows.HANDLE,
+        Os.linux => i32,
+        Os.windows => windows.HANDLE,
         else => @compileError("Unsupported OS"),
     };
 
@@ -2919,7 +2922,7 @@ pub const Thread = struct {
     /// May be an integer or pointer depending on the platform.
     /// On Linux and POSIX, this is the same as Handle.
     pub const Id = switch (builtin.os) {
-        builtin.Os.windows => windows.DWORD,
+        Os.windows => windows.DWORD,
         else => Handle,
     };
 
@@ -2930,12 +2933,12 @@ pub const Thread = struct {
             mmap_len: usize,
         }
     else switch (builtin.os) {
-        builtin.Os.linux => struct {
+        Os.linux => struct {
             handle: Thread.Handle,
             mmap_addr: usize,
             mmap_len: usize,
         },
-        builtin.Os.windows => struct {
+        Os.windows => struct {
             handle: Thread.Handle,
             alloc_start: *c_void,
             heap_handle: windows.HANDLE,
@@ -2951,8 +2954,8 @@ pub const Thread = struct {
             return c.pthread_self();
         } else
             return switch (builtin.os) {
-            builtin.Os.linux => linux.gettid(),
-            builtin.Os.windows => windows.GetCurrentThreadId(),
+            Os.linux => linux.gettid(),
+            Os.windows => windows.GetCurrentThreadId(),
             else => @compileError("Unsupported OS"),
         };
     }
@@ -2979,7 +2982,7 @@ pub const Thread = struct {
             }
             assert(posix.munmap(self.data.mmap_addr, self.data.mmap_len) == 0);
         } else switch (builtin.os) {
-            builtin.Os.linux => {
+            Os.linux => {
                 while (true) {
                     const pid_value = @atomicLoad(i32, &self.data.handle, .SeqCst);
                     if (pid_value == 0) break;
@@ -2993,7 +2996,7 @@ pub const Thread = struct {
                 }
                 assert(posix.munmap(self.data.mmap_addr, self.data.mmap_len) == 0);
             },
-            builtin.Os.windows => {
+            Os.windows => {
                 assert(windows.WaitForSingleObject(self.data.handle, windows.INFINITE) == windows.WAIT_OBJECT_0);
                 assert(windows.CloseHandle(self.data.handle) != 0);
                 assert(windows.HeapFree(self.data.heap_handle, 0, self.data.alloc_start) != 0);
@@ -3046,7 +3049,7 @@ pub fn spawnThread(context: var, comptim
     const Context = @typeOf(context);
     comptime assert(@ArgType(@typeOf(startFn), 0) == Context);
 
-    if (builtin.os == builtin.Os.windows) {
+    if (builtin.os == Os.windows) {
         const WinThread = struct {
             const OuterContext = struct {
                 thread: Thread,
@@ -3120,7 +3123,7 @@ pub fn spawnThread(context: var, comptim
         }
     };
 
-    const MAP_GROWSDOWN = if (builtin.os == builtin.Os.linux) linux.MAP_GROWSDOWN else 0;
+    const MAP_GROWSDOWN = if (builtin.os == Os.linux) linux.MAP_GROWSDOWN else 0;
 
     var stack_end_offset: usize = undefined;
     var thread_start_offset: usize = undefined;
@@ -3183,7 +3186,7 @@ pub fn spawnThread(context: var, comptim
             posix.EINVAL => unreachable,
             else => return unexpectedErrorPosix(@intCast(usize, err)),
         }
-    } else if (builtin.os == builtin.Os.linux) {
+    } else if (builtin.os == Os.linux) {
         var flags: u32 = posix.CLONE_VM | posix.CLONE_FS | posix.CLONE_FILES | posix.CLONE_SIGHAND |
             posix.CLONE_THREAD | posix.CLONE_SYSVSEM | posix.CLONE_PARENT_SETTID | posix.CLONE_CHILD_CLEARTID |
             posix.CLONE_DETACHED;
@@ -3251,11 +3254,11 @@ pub const CpuCountError = error{
 
 pub fn cpuCount(fallback_allocator: *mem.Allocator) CpuCountError!usize {
     switch (builtin.os) {
-        builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd => {
+        Os.macosx, Os.freebsd, Os.netbsd, Os.dragonfly => {
             var count: c_int = undefined;
             var count_len: usize = @sizeOf(c_int);
             const rc = posix.sysctlbyname(switch (builtin.os) {
-                builtin.Os.macosx => c"hw.logicalcpu",
+                Os.macosx => c"hw.logicalcpu",
                 else => c"hw.ncpu",
             }, @ptrCast(*c_void, &count), &count_len, null, 0);
             const err = posix.getErrno(rc);
@@ -3271,7 +3274,7 @@ pub fn cpuCount(fallback_allocator: *mem
                 else => return os.unexpectedErrorPosix(err),
             }
         },
-        builtin.Os.linux => {
+        Os.linux => {
             const usize_count = 16;
             const allocator = std.heap.stackFallback(usize_count * @sizeOf(usize), fallback_allocator).get();
 
@@ -3303,7 +3306,7 @@ pub fn cpuCount(fallback_allocator: *mem
                 }
             }
         },
-        builtin.Os.windows => {
+        Os.windows => {
             var system_info: windows.SYSTEM_INFO = undefined;
             windows.GetSystemInfo(&system_info);
             return @intCast(usize, system_info.dwNumberOfProcessors);
